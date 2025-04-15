#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>
#include <chrono>


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
            {
                maxProduct = product;
                //std::cout << " In MaxPairwiseProductNaive => "<<numbers[index] << " * " << numbers[secondIndexComparing] << " = " << maxProduct << "\n";
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

    //std::cout << " In MaxPairwiseProductFast => " << numbers[maxNbrIndex] << " * " << numbers[maxSecondNbrIndex] << " = " << 1LL * numbers[maxNbrIndex] * numbers[maxSecondNbrIndex] << "\n";
    return 1LL * numbers[maxNbrIndex] * numbers[maxSecondNbrIndex];
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
    
    //std::cout << MaxPairwiseProductNaive(numbers); //Fisrt work submit
    std::cout << MaxPairwiseProductFast(numbers); 
        
    return 0;
}