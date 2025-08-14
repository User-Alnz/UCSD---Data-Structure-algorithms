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

    auto start = high_resolution_clock::now();
        std::vector<int> result = minimumKSegment(segmentList);
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
        Assignement :
        
            Constraints. 
            1 ≤ n ≤ 100; 
            0 ≤ li ≤ ri ≤ 10^9 for all i. segement like {2, 3} or {li, ri}


        return k => number of minimal commun point of multiple segment sharing same area.

        and k List of commun number k from group. 
    */

    // runTest( testnbr, vectorOFacceptableResultOf_k, segmentListToBeTreated);  

    //TEST in ordered list of segment. 2 group of segment sharing 2 possible k points = {3, 4} or {6, 8}
    runTest(1, { {3, 4}, {6, 8}} , {{1, 4}, {2 ,5}, {3, 6}, {6, 8}}); 

    //TEST unordered list of segment. 1 group of segment sharing 1 possible k point = {5, 6}
    runTest(2, {{5, 6}}, { {2 , 6}, { 5, 8 }, { 5, 10 }, {4, 10}});

    //TEST unordered list of segment. 3 group of segment sharing 3 possible k point = {4, 5} or {1, 2} or {6}
    runTest(3, {{1, 2}, {4}, {6}},  {{4, 5}, {1, 2}, {3, 4}, {5, 6}, {6, 7}});

    // test 3 not passed ! must sort array ASC or DESC and attribute k as first or second depending ASC or DESC sorting order !! 
    //NOT PASSED => [ 5  1  6 ] & expected is among expected result : [{ 4 } { 1 2 } { 6 } ]⏎   

    runTest(4, {{3}, {6}}, {{4,7},{1,3},{2,5},{5,6}});

    /*
        Best option is thus sorting segment O(n log n) by using quick sort or merge Sort. 

        next apply minimumKSegment() which is O(n²) worst case or tend to O(n) best case
        as it keep seaching k excluding from previous index of min k.
    */

    return 0;
}