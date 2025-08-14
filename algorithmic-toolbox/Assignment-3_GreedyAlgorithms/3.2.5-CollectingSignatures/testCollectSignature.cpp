#include <iostream>
#include <vector>
#include <algorithm>
#include "collectingSignature.h"


int min(int &a, int &b)
{
    if(a < b)
    return a;
    else
    return b;
}

std::vector <int> minimumKSegment(std::vector <std::pair<int, int>> & segmentList)
{
    std::vector <int> listOfMinimumK;
    std::vector <int> treatedSegment(segmentList.size(), 0);
    std::pair <int, int> scanSegment;

    //Sort O(n log n)
    std::sort(segmentList.begin(), segmentList.end());
    

    int k = 0;
    int index = 0;
    int flag = 0;
    int memoizedIndex = 0;

    while(true)
    {
        index = memoizedIndex;
        k = 0;
        flag = 0;

        scanSegment.second = segmentList[index].second;
        k = scanSegment.second;

        while(index < segmentList.size())
        {   
            
            if(segmentList[index].first <= k)
            {
                k = min(k, segmentList[index].second);
                treatedSegment[index] = 1;
            }

            index++;
        }

        listOfMinimumK.push_back(k);
        
        index = memoizedIndex;
        while(index < treatedSegment.size())
        {
            if(treatedSegment[index] == 0)
            {
                flag = index;
                memoizedIndex = index;
                break;
            }

            index++;
        }
        
        if(flag == 0)
        break;
        
    }

    return listOfMinimumK; 
}