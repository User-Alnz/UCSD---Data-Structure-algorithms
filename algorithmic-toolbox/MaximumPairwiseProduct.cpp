#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>


long long MaxPairwiseProductNaive(const std::vector<int>& numbers){ //only read by reference

    size_t  index = 0;
    size_t  secondIndexComparing = 0;
    long long     maxProduct = 0;

    while(index < numbers.size())
    {   
        secondIndexComparing = 0;
        while(secondIndexComparing < numbers.size())
        {
            long long product = 1LL * numbers[index] * numbers[secondIndexComparing];//1LL to avoid int overflow
            if(maxProduct < product && (index != secondIndexComparing))
                maxProduct = product;
                //Debugging Only //std::cout << " In MaxPairwiseProductNaive => "<<numbers[index] << " * " << numbers[secondIndexComparing] << " = " << maxProduct << "\n";
            
            secondIndexComparing++;
        }
        index++;
    }
    return maxProduct;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers){

    size_t  index = 0;
    int maxNbr = 1;
    int maxSecondNbr = 1;
     
    while(index < numbers.size())
    {   
        if(maxNbr < numbers[index])
            maxNbr = numbers[index];
        index++;
    }

    index = 0;
    while(index < numbers.size())
    {
        if(maxNbr != numbers[index] && maxSecondNbr < numbers[index])
            maxSecondNbr = numbers[index];
        index++;
    }
    //Debugging Only //std::cout << " In MaxPairwiseProductFast => " << maxNbr << " * " << maxSecondNbr << " = " << 1LL * maxNbr * maxSecondNbr << "\n";

    return 1LL * maxNbr * maxSecondNbr;
}

void StressTest(){
    while(true)
    {
        std::srand(std::time(nullptr)); //implement random on second
        std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count()); // implement on nanoseconds perfect for looping sample rng

        int randomNumber;
        randomNumber =  std::rand() % 10 + 2;
        std::cout << randomNumber << "\n";

        int rangeTo = 0;
        std::vector<int> ArrayOfInteger;

        while(rangeTo++ < randomNumber) { //Fill array with Integer
            int random = rng() % 100000; // 10ˆ5 number
            ArrayOfInteger.push_back(random);
        }

        for (int eachNumberIn : ArrayOfInteger) { //Print numbers in Array to be tested
            std::cout << eachNumberIn << " ";
        }
        std::cout << "\n";

        long long result1 = MaxPairwiseProductNaive(ArrayOfInteger);
        long long result2 = MaxPairwiseProductFast(ArrayOfInteger);

        if(result1 == result2)
            std::cout << "Ok\n";
        else
            std::cout << "Wrong answer " << result1 << " != " << result2 << "\n";
    }
}

int main(){
    
    int     firstNbr;
    size_t  index = 0; //unsigned int
    std::cin >>     firstNbr; //Allocate int parameter to fisrtnbr
    std::vector<int>    numbers(firstNbr); //initiate vector

    while(index < firstNbr){
       std::cin >> numbers[index];
       index++;
    }

    std::cout << MaxPairwiseProductNaive(numbers); //Fisrt work submit
    //std::cout << MaxPairwiseProductFast(numbers); 
    
    //Only for Testing  //StressTest();
    
    return 0;
}