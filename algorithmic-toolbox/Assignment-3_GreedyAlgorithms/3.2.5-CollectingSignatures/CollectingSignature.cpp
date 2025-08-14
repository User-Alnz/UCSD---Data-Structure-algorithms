#include <iostream>
#include <vector>
#include <algorithm>

    /*
        Solution is O(n²)
        Altough small optimization with 

        Assignement :
        
        Constraints:

        1 ≤ n ≤ 100; 
        0 ≤ li ≤ ri ≤ 10^9 for all i. segement like {2, 3} or {li, ri}
    */
void printVectorPair(const std::vector <std::pair<int, int>> & vector)
{
    int idx = 0;
    std::cout << "[";

    for(const auto& index : vector) 
    {
        std::cout << " { " << index.first << " , " << index.second << " } ";
        idx++;
    }

    std::cout << "]";
}

void printVector(const std::vector<int> &vector)
{
    int idx = 0;
    
    while(idx < vector.size())
    {
        std::cout << " " << vector[idx] << " ";
        idx++;
    }

}

int max(int &a, int &b)
{
    if(a > b)
    return a;
    else
    return b;
}

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
    printVectorPair(segmentList);

    int k = 0;
    int index = 0;
    int lag = 0;
    int memoizedIndex = 0;

    while(true)
    {
        index = memoizedIndex;
        k = 0;
        flag = 0;

        scanSegment.first = segmentList[index].first;
        scanSegment.second = segmentList[index].second;

        while(index < segmentList.size())
        {   

            
            if(segmentList[index].second >= scanSegment.first && segmentList[index].first <= scanSegment.second)
            {
                k = min(scanSegment.second, segmentList[index].second); //in ordered ASC safer choice is the upmost min Seg ri

                treatedSegment[index] = 1;   
            }

            std::cout << "scanning current seg = [ "<< scanSegment.first << " " << scanSegment.second << " ];  ";
            std::cout << "compare to " << "[ " << segmentList[index].first << " " << segmentList[index].second << " ];\nfor k ==";
            std::cout << k << "\n";   
                   
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

        printVector(treatedSegment);
        std::cout<<"\n";

        if(flag == 0)
        break;
        
    }

    return listOfMinimumK; 
}


int main()
{
    
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

    int minimumK = 0;
    std::vector<int> result = minimumKSegment(testList);

    minimumK = result.size();
    std::cout << minimumK << " \n";
    printVector(result);
        
}