#include <iostream>
#include <vector>

int MaxPairwise(const std::vector<int>& numbers){ //only read by reference

    size_t  index = 0;
    size_t  secondIndexComparing = 0;
    int     maxProduct = 0;

    while(index < numbers.size() )
    {   
        secondIndexComparing = 0;
        while(secondIndexComparing < numbers.size())
        {
            if(maxProduct < (numbers[index] * numbers[secondIndexComparing]) && (index != secondIndexComparing))
                maxProduct = numbers[index] * numbers[secondIndexComparing];
            
            secondIndexComparing++;
        }
        index++;
    }
    return maxProduct;
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

    std::cout << MaxPairwise(numbers);

    return 0;
}