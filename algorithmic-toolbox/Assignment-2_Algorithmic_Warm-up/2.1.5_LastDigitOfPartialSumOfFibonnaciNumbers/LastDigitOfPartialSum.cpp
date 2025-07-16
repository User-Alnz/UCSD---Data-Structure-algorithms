#include <iostream>
#include <vector>


void printPisanoSequence(std::vector<long long> PisanoArray)
{
    int idx = 0;
    std::cout << "[";

    while(idx < PisanoArray.size())
    {
        std::cout << " " << PisanoArray[idx] << " ";
        idx++;
    }

    std::cout << "]";
}

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
    //int index = 0;
    int sum = fib[0];

    printPisanoSequence(fib);
    std::cout << "\n\n";
    while(FromPositionInSequence <= ToPositionInSequence)
    {
        sum += fib[FromPositionInSequence];
        std::cout << " + " << fib[FromPositionInSequence];
        FromPositionInSequence++;
    }

    std::cout << "\n\tsum result is equal to : " << sum;
    sum = sum%10;//Only keep last digit in sequence sum. Avoid digit > 10.

    std::cout << "\n\tlast number is equal to : " << sum;
    return sum;
}

int FastLastDigitOfFibPartialSum(long long m, long long n)
{
    int moduloNb = 10;
    int result;

    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size(); //modulo 10 Pisano always go from 0 to 60 and repeat cycle
    std::cout << "\n\tSequenceLength is : " << sequenceLength << "\n\n";

    int ToPositionInSequence = n % sequenceLength;
    int FromPositionInSequence = m % sequenceLength;
    
    std::cout << "\n\tFor m Position in sequence is : " << FromPositionInSequence;
    std::cout << "\n\tFor n Position in sequence is : " << ToPositionInSequence << "\n\n";

    result = sumUpInPisanoSequence(PisanoArray, FromPositionInSequence, ToPositionInSequence);

    return result;
}

int main()
{
    // Constraints. 0 ≤ m ≤ n ≤ 1014 .
    long long Fib_m;
    long long Fib_n;

    std::cin >> Fib_m >> Fib_n;

    int result = FastLastDigitOfFibPartialSum(Fib_m, Fib_n);

    std::cout << "\nResult is : " <<result << "\n";
}