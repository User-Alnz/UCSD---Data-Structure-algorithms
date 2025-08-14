#include <cassert>
#include <iostream>
#include <chrono>
#include <algorithm>
#include "collectingSignature.h"
#include "printVector.h"

// compile me =>  g++ -pipe -O2 -std=c++11 -I../../includeOwnTools testCollectSignature.cpp mainTest.cpp -o test
// run me => ./test

void runTest(
    int testIndex, 
    std::vector <std::vector<int>> expectedResult, 
    const std::vector <std::pair<int, int>> & segmentList
)
{

    bool testPassed = true;

    using namespace std::chrono;

    std::vector <std::pair<int, int>> segmentCopy = segmentList;

    auto start = high_resolution_clock::now();
        std::vector<int> result = minimumKSegment(segmentCopy);
    auto stop = high_resolution_clock::now();



    if (result.size() != expectedResult.size()) {
        std::cout << "Wrong answer: minimum k found " << result.size() << " != expected minimum k " << expectedResult.size() << "\n";
        testPassed = false;
    } 
    else 
    {
        for (size_t i = 0; i < result.size(); i++) 
        {
            if (std::find(expectedResult[i].begin(), expectedResult[i].end(), result[i]) == expectedResult[i].end()) {
                testPassed = false;
                break;
            }
        }
    }

    if(testPassed)
    {
        std::cout << "result is good => "; OutputArray::printVector(result); 
        std::cout << " & expected is among expected result : "; OutputArray::print2DVector(expectedResult);
        auto duration = duration_cast<microseconds>(stop - start);
        std::cout << "\n| running time is = " << duration.count() << " µs\n";
    }
    else{
        std::cout << "NOT PASSED => "; OutputArray::printVector(result); 
        std::cout << " & expected is among expected result : "; OutputArray::print2DVector(expectedResult);
    }
        
}
    

int main()
{
    
    /*
        test prototype => runTest( testnbr, vectorOFacceptableResultOf_k, segmentListToBeTreated);  
    */


    //TEST in ordered list of segment. 2 group of segment sharing 2 possible k points = {3, 4} or {6, 8}
    runTest(1, { {3, 4}, {6, 8}} , {{1, 4}, {2 ,5}, {3, 6}, {6, 8}}); 

    //TEST unordered list of segment. 1 group of segment sharing 1 possible k point = {5, 6}
    runTest(2, {{5, 6}}, { {2 , 6}, { 5, 8 }, { 5, 10 }, {4, 10}});

    //TEST unordered list of segment. 3 group of segment sharing 3 possible k point = {4, 5} or {1, 2} or {6}
    runTest(3, {{1, 2}, {4}, {6}},  {{4, 5}, {1, 2}, {3, 4}, {5, 6}, {6, 7}});

    runTest(4, {{3}, {6}}, {{4,7},{1,3},{2,5},{5,6}});

    return 0;
}