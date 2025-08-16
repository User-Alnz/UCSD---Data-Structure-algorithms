#include <iostream>
#include <vector>


void printVector(const std::vector<int> &vector)
{
    int idx = 0;
    while(idx < vector.size())
    {
        std::cout << vector[idx] << " ";
        idx++;
    }
}

int minSequenceSumOfConsecutiveNumb(int & nbr, const int & n)
{
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

    nbr = 1;
    while(nbr <= minSequence)
    {
        maxSum += nbr;
        minSumOfIntList.push_back(nbr);
        nbr++;
    }

    rest = n - maxSum;
    minSumOfIntList[minSumOfIntList.size()-1] += rest; 


    std::cout << minSequence << "\n";
    printVector(minSumOfIntList);
}



int main()
{
    int n;

    std::cin >> n;

    MaxNumberOfPrizes(n);

    return 0;
}