#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>


long long MaxPairwiseProductNaive(const std::vector<int>& numbers){

    size_t  index = 0;
    size_t  secondIndexComparing = 0;
    long long     maxProduct = 0;

    while(index < numbers.size())
    {   
        secondIndexComparing = 0;
        while(secondIndexComparing < numbers.size())
        {
            long long product = 1LL * numbers[index] * numbers[secondIndexComparing];
            if(maxProduct < product && (index != secondIndexComparing))
            {
                maxProduct = product;
                std::cout << " In MaxPairwiseProductNaive => "<<numbers[index] << " * " << numbers[secondIndexComparing] << " = " << maxProduct << "\n";
            }
                
            secondIndexComparing++;
        }
        index++;
    }
    return maxProduct;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers){

    size_t  index_1 = 0;
    size_t  index_2 = 0;
    int maxNbrIndex = 0;
    int maxSecondNbrIndex = 0;
     
    while(index_1 < numbers.size())
    {   
        if(numbers[index_1] > numbers[maxNbrIndex])
            maxNbrIndex = index_1;

        index_1++;
    }

    if(maxNbrIndex == 0)
        maxSecondNbrIndex = 1;

    while(index_2 < numbers.size())
    {
        if(index_2 != maxNbrIndex && numbers[index_2] > numbers[maxSecondNbrIndex])
            maxSecondNbrIndex = index_2;

        index_2++;
    }

    std::cout << " In MaxPairwiseProductFast => " << numbers[maxNbrIndex] << " * " << numbers[maxSecondNbrIndex] << " = " << 1LL * numbers[maxNbrIndex] * numbers[maxSecondNbrIndex] << "\n";
    return 1LL * numbers[maxNbrIndex] * numbers[maxSecondNbrIndex];
}

void StressTest(){
    while(true)
    {
        std::srand(std::time(nullptr)); //implement random on second
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count()); // implement on nanoseconds perfect for looping sample rng

        int randomNumber;
        randomNumber =  std::rand() % 10 + 2; // Define "N" which is the number of int populating array to be tested 
        std::cout << randomNumber << "\n";

        int rangeTo = 0;
        std::vector<int> ArrayOfInteger;

        while(rangeTo++ < randomNumber) { //Fill array with Integer
            int random = rng() % 100000; // 10ˆ5 number // Define "n" the max value of a int in array
            ArrayOfInteger.push_back(random);
        }

        for (int eachNumberIn : ArrayOfInteger) { //Print numbers in Array to be tested
            std::cout << eachNumberIn << " ";
        }
        std::cout << "\n";

        long long result2 = MaxPairwiseProductFast(ArrayOfInteger);
        long long result1 = MaxPairwiseProductNaive(ArrayOfInteger);
       
        if(result1 == result2)
            std::cout << "Ok\n";
        else{
            std::cout << "Wrong answer " << result1 << " != " << result2 << "\n";
            break;
        } 
    }
}

int main(){
 
    StressTest();
    return 0;
}