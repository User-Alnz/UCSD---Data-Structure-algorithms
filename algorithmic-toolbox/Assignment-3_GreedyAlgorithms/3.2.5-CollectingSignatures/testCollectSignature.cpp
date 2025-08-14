#include <iostream>
#include <vector>
#include <algorithm>
#include "collectingSignature.h"



std::vector <int> minimumKSegment(const std::vector <std::pair<int, int>> & segmentListOriginal)
{
    std::vector <int> listOfMinimumK;
    std::vector <int> treatedSegment(segmentListOriginal.size(), 0);
    std::pair <int, int> scanSegment;

    std::vector<std::pair<int,int>>  segmentList = segmentListOriginal; //make a copy
    std::sort(segmentList.begin(), segmentList.end());
    
    int  flag = 0;
    int k = 0;
    int index = 0;
    int memoizedIndex = 0;
    
    while(true)
    {
        index = flag;
        k = 0;
        flag = 0;

        scanSegment.first = segmentList[index].first;
        scanSegment.second = segmentList[index].second;

        while(index < segmentList.size())
        {   
            
            if((scanSegment.first >= segmentList[index].first && scanSegment.first <= segmentList[index].second) || 
                (scanSegment.second <= segmentList[index].second && scanSegment.second >= segmentList[index].first))
            {
                if(scanSegment.first >= segmentList[index].first)
                    k = scanSegment.first;

                if(scanSegment.second <= segmentList[index].second)
                    k = scanSegment.second;


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