#include <cassert>
#include <iostream>
#include <chrono>
#include "CarFueling.h"

// compile me =>  g++ -pipe -O2 -std=c++11 testCarFueling.cpp mainTest.cpp  -o test
// test me => ./test

void runTest(
    int testIndex, 
    int expectedResult, 
    int distance,
    int gazTankMaxCapacity,
    int nbrOfStops,
    const std::vector<int>& stopsOnRoad)
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
        int result = minimumNumberOfRefill(distance, gazTankMaxCapacity, nbrOfStops, stopsOnRoad);
    auto stop = high_resolution_clock::now();


    if(result != expectedResult)
        std::cout << "Wrong answer : result  " << result << " !=  expected result " << expectedResult;
    else
        std::cout << "result is good => " << result << " & expected is : " << expectedResult;

    auto duration = duration_cast<microseconds>(stop - start);
    std::cout << " | running time is = " << duration.count() << " µs\n";

    assert(result == expectedResult);
}

int main() 
{

    // Test 1: classic case 
    runTest(1, 2, 950, 400, 4, {200, 375, 550, 750}); 
    
    // Test 2: No refill needed
    runTest(2, 0 ,300, 400, 3, {100, 200, 250}); 
    
    // Test 3: Impossible to reach
    runTest(3, -1, 10, 3, 4, {1, 2, 5, 9 });

    // Test 4: Exact stops
    runTest(4, 2, 700, 300, 2, {300, 600});

    return 0;
}
