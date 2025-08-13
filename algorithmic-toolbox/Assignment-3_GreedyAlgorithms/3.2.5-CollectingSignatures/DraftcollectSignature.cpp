#include <iostream>
#include <vector>
#include "MergeSort.h" 
#include "printVector.h"

std::vector <int> minimumKSegment(std::vector <std::pair<int, int>> & segmentList)
{
        
    std::vector <int> listOfMinimumK;
    std::vector <int> treatedSegment(segmentList.size(), 0);
    std::pair <int, int> scanSegement;
    
    int  flag = 0;
    int k = 0;
    int index = 0;
    //OutputArray::printVector(treatedSegment);
    
    while(true)
    {
        index = flag;
        k = 0;
        flag = 0;

        scanSegement.first = segmentList[index].first;
        scanSegement.second = segmentList[index].second;

        while(index < segmentList.size())
        {   
            
            // k >= li =< ri;
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
                 
            //std::cout << k << "\n";
            
            index++;
        }

        //OutputArray::printVector(treatedSegment);

        listOfMinimumK.push_back(k);
        
        index =0;
        while(index < treatedSegment.size())
        {
            if(treatedSegment[index] == 0)
                flag = index;

            index++;
        }
        
        std::cout << "\n" << flag << "\n";
        if(flag == 0)
        break;
        
    }

    return listOfMinimumK; 
}



int main()
{
    /*
        Constraints. 
        1 ≤ n ≤ 100; 
        0 ≤ li ≤ ri ≤ 10^9 for all i. segement like {2, 3} or {li, ri}
    */

    int nbrOfSegment;
    std::vector <std::pair<int, int>> segmentList;

    std::cin >> nbrOfSegment;

    for(int agrs =0; agrs < nbrOfSegment; agrs++)
    {
        int li;
        int ri;

        std::cin >> li >> ri;
        segmentList.push_back({li, ri});
    }

    //std::vector <int> list = { 9, 6, 2, 4, 1 , 8, 22};

    
    MergeSort<std::pair<int, int>>  sortingMethod;
    sortingMethod.mergePairFirstASC(segmentList);

    std::vector <std::pair<int, int>> testList = { {1, 4 }, { 2, 5 }, {3, 6}, {6, 8} };

    OutputArray::printVectorPair(testList);


    std::vector<int> result = minimumKSegment(testList);
    std::cout << "\n";
    OutputArray::printVector(result);

    //std::cout << "\n" << minimumKSegment(testList);


    return 0;
}