#include <iostream>
#include <vector>
#include "collectingSignature.h"

std::vector <int> minimumKSegment(const std::vector <std::pair<int, int>> & segmentList)
{
    std::vector <int> listOfMinimumK;
    std::vector <int> treatedSegment(segmentList.size(), 0);
    std::pair <int, int> scanSegement;
    
    int  flag = 0;
    int k = 0;
    int index = 0;
    
    while(true)
    {
        index = flag;
        k = 0;
        flag = 0;

        scanSegement.first = segmentList[index].first;
        scanSegement.second = segmentList[index].second;

        while(index < segmentList.size())
        {   
            if(treatedSegment[index] == 1)
                index++;

            if(scanSegement.first >= segmentList[index].first || (scanSegement.second <= segmentList[index].second && scanSegement.second >= segmentList[index].first))
            {

                if(scanSegement.first >= segmentList[index].first)
                    k = scanSegement.first;

                if(scanSegement.second <= segmentList[index].second)
                    k = scanSegement.second; 

                treatedSegment[index] = 1;
            }
            
            if(k==0)
            {
                k = scanSegement.first;
                treatedSegment[index] = 1;
            }
                             
            index++;
        }

        listOfMinimumK.push_back(k);
        
        index =0;
        while(index < treatedSegment.size())
        {
            if(treatedSegment[index] == 0)
                flag = index;

            index++;
        }
        
        if(flag == 0)
        break;
        
    }

    return listOfMinimumK; 
}