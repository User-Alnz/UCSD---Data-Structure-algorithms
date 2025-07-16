#include <vector>
#include <iostream>

std::vector<long long> PisanoPeriodSequence(int moduloNb)
{
    int index = 2;
    long long pisanoNumber;
    std::vector<long long> fib = { 0, 1 };

    while(true)
    {
        pisanoNumber =  (fib[fib.size() - 1] + fib[fib.size() - 2]) % moduloNb;
        fib.push_back(pisanoNumber);
            
            if (fib[fib.size() - 2] == 0 && fib[fib.size() - 1] == 1 && fib.size() > 2)
            {
                fib.pop_back();
                fib.pop_back();
                return fib; 
            }
        index++;
    }
}


int sumUpInPisanoSequence(std::vector<long long> fib, int FromPositionInSequence,int ToPositionInSequence)
{
    int sum = fib[0];

    while(FromPositionInSequence <= ToPositionInSequence)
    {
        sum += fib[FromPositionInSequence];
        FromPositionInSequence++;
    }

    sum = sum%10;

    return sum;
}

int FastLastDigitOfFibPartialSum(long long m, long long n)
{
    int moduloNb = 10;
    int result;

    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size();

    int ToPositionInSequence = n % sequenceLength;
    int FromPositionInSequence = m % sequenceLength;

    int delta = ToPositionInSequence - FromPositionInSequence;

    if(delta < 0) 
    {
        int preSequence = sumUpInPisanoSequence(PisanoArray, FromPositionInSequence, sequenceLength-1);
        int postSequence = sumUpInPisanoSequence(PisanoArray, 0, ToPositionInSequence);
        result = (preSequence + postSequence)%10;
        return result;
    }

    result = sumUpInPisanoSequence(PisanoArray, FromPositionInSequence, ToPositionInSequence);

    return result;
}

int main()
{
    long long Fib_m;
    long long Fib_n;

    std::cin >> Fib_m >> Fib_n;
    std::cout << FastLastDigitOfFibPartialSum(Fib_m, Fib_n);
}