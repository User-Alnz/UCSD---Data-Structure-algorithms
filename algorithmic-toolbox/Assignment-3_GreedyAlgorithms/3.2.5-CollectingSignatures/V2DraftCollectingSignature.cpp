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
    int memoizedIndex = 0;

    OutputArray::printVector(treatedSegment);
    std::cout << "\n\n";
    
    while(true)
    {
        index = flag; // skip already treated value!
        k = 0;
        flag = 0;

        scanSegement.first = segmentList[index].first;
        scanSegement.second = segmentList[index].second;

        while(index < segmentList.size())
        {   
            
            /*
                remember S segment is S = [li, ri] like 0 ≤ li ≤ ri ≤ 10^9. li max left seg and ri max right seg.
                k >= li =< ri;
                to get sure k is in range of S segment.
                
                S1 li >= S2 li && S1 li <= S2 ri. 
                S1 ri <= S2 ri && S2 ri >= S2 li.

                if condition is met k is in range of S2 [li, ri];
            */
            if(((scanSegement.first >= segmentList[index].first && scanSegement.first <= segmentList[index].second) || 
                (scanSegement.second <= segmentList[index].second && scanSegement.second >= segmentList[index].first) )
                && treatedSegment[index] != 1)
            {

                //There change order of condition flow to keep either greatest or lower k. current choice is better if sort in ASC order.
                if(scanSegement.second <= segmentList[index].second)
                    k = scanSegement.second;

                if(scanSegement.first >= segmentList[index].first)
                    k = scanSegement.first;
 
                treatedSegment[index] = 1;
            }

            std::cout << "scanning current seg = [ "<< scanSegement.first << " " << scanSegement.second << " ];  ";
            std::cout << "compare to " << "[ " << segmentList[index].first << " " << segmentList[index].second << " ];\nfor k ==";
            std::cout << k << "\n";
            
            index++;
        }

        OutputArray::printVector(treatedSegment);

        listOfMinimumK.push_back(k);
        
        //This is responsible to found value until not treated. and pass index to next loop until all values got treated.

        index = memoizedIndex;//never restart from 0 to skip values already read.
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

    //std::vector <std::pair<int, int>> testList = { {1, 4 }, { 2, 5 }, {3, 6}, {6, 8} };
    std::vector <std::pair<int, int>> testList = {{4, 5}, {1, 2}, {3, 4}, {5, 6}, {6, 7}};

    //std::vector <std::pair<int, int>> testList = {{4, 5}, {1, 2}, {3, 4}, {5, 6}, {6, 7}, {8,10}};

    //OutputArray::printVectorPair(testList);
    sortingMethod.mergePairFirstASC(testList);
    OutputArray::printVectorPair(testList);

    std::vector<int> result = minimumKSegment(testList);
    std::cout << "\n";
    OutputArray::printVector(result);

    //std::cout << "\n" << minimumKSegment(testList);


    return 0;
}