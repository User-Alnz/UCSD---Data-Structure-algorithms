#include <cassert>
#include <iostream>
#include <chrono>
#include "MaxAdRevenue.h"


// compile me =>  g++ -pipe -O2 -std=c++11 testMaxAdRevenue.cpp mainTest.cpp  -o test
// test me => ./test

void runTest(
    int testIndex, 
    long long expectedResult, 
    const std::vector<int> & price, 
    const std::vector<int> & clicks
)
{
    using namespace std::chrono;

    auto start = high_resolution_clock::now();
        long long result = maxAdRevenue(price, clicks);
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

    runTest(1, 897, {23}, {39}); 
    
    runTest(2, 79, {2, 3, 9}, {7, 4, 2});

    runTest(3 , 478 , {20, 1, 6, 2, 30}, {10, 7, 1, 0, 6});
    
    //test data type overflow 
    runTest( 4 , 20000000000, { 100000, 100000}, { 100000, 100000});
    
    return 0;
}
