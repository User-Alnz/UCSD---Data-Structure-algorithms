#include <iostream>
#include <vector>


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

int sumUpToPisanoSequenceIndex(std::vector<long long> fib, long long PositionInSequence)
{
    int index = 0;
    int sum = fib[0];

    while(index <= PositionInSequence)
    {
        sum += fib[index];
        sum = sum%10;
        index++;
    }

    return sum;
}


int FastLastFibNumber(long long n)
{
    int moduloNb = 10;
    int result;

    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size();
    long long PositionInSequence = n % sequenceLength;

    result = sumUpToPisanoSequenceIndex(PisanoArray, PositionInSequence);

    return result;
}

int main()
{
    int Fib_n;
    std::cin >> Fib_n;

    int result = FastLastFibNumber(Fib_n);
    std::cout << result;
}