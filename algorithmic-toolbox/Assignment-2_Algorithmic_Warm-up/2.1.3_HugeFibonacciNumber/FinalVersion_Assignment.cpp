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

int FastHugeFibNumber(long long n, int moduloNb)
{
    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size();
    long long PositionInSequence = n % sequenceLength;

    return PisanoArray[PositionInSequence];
}

int main()
{
    long long n;
    int moduloNb;

    std::cin >> n;
    std::cin >> moduloNb;

    std::cout << FastHugeFibNumber(n, moduloNb);

}