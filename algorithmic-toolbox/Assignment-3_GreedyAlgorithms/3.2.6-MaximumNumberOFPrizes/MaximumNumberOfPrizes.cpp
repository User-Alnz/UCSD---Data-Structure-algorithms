#include <iostream>
#include <vector>
#include "printVector.h"

// Compile me this way => g++ -pipe -O2 -std=c++11 -I../../includeOwnTools  MaximumNumberOfPrizes.cpp -o test
// run me => ./test

int minSequenceSumOfConsecutiveNumb(int & nbr, const int & n)
{
    /*
        This function rely on Gaus Formula

        we can determine position in sequence / result of consecutive nbr sum 1 + 2 + 3 + 4 [...]
        by following this formula : nbr*(nbr+1)/2;

        like 3 is 6 because result r is defined as following :

        r1 = 1*(1+1)/2 = 1; (or 1)
        r2 = 2*(2+1)/2 = 3; (or 1 + 2)
        r3 = 3*(3+1)/2 = 6; (or 1 + 2 + 3)
        r4 = 4*(4+1)/2 = 10; (or 1 + 2 + 3 + 4)
        [...]
        
        So to find out minimum sequence of consecutive numb r <= n; to workout minimum sequence.
    */

    int minSumOfConsecutiveInt = 0;

    while(true)
    {
        nbr++;
        minSumOfConsecutiveInt = nbr * (nbr+1) /2;

        if(minSumOfConsecutiveInt == n)
            break;
        else if(minSumOfConsecutiveInt >= n)
        {
            nbr--;
            break;
        }
    }
    
    return nbr;
}



void MaxNumberOfPrizes( int n )
{
    int nbr = 0;
    std::vector <int> minSumOfIntList;
    int maxSum = 0;
    int rest = 0;

    
    int minSequence = minSequenceSumOfConsecutiveNumb(nbr, n);
    std::cout << "minsequence =  " << minSequence << "\n";

    nbr = 1;
    while(nbr <= minSequence)
    {
        maxSum += nbr;
        minSumOfIntList.push_back(nbr);
        nbr++;
    }

    /*
        Once minnimum sequence is found simply workout rest to reach n. 
        like rest = n - maxSumOfConsecutiveNumber for instance and sum it up to last digit in list.

        Exemple for n = 8 
             
        r = 3 like  r3 = 3*(3+1)/2 = 6
        r4 = 4*(4+1)/2 = 10 

        r3 = (1 + 2 + 3) < n < r4 = (1 + 2 + 3 + 4)
        r3 < 8 < r4 
        We keep r3 because <= 8

        now to define rest number as rn. 

        rn = n - r3  
        rn = 8 - 6
        rn = 2

        Output is => r3 = (1 + 2 + (3 + rn )) 
        Output is => (1 + 2 + 5)
    */

    rest = n - maxSum;
    minSumOfIntList[minSumOfIntList.size()-1] += rest; 

    std::cout << minSequence << "\n";
    OutputArray::printVector(minSumOfIntList);
}



int main()
{
    int n;
    std::cin >> n;

    MaxNumberOfPrizes(n);

    return 0;
}