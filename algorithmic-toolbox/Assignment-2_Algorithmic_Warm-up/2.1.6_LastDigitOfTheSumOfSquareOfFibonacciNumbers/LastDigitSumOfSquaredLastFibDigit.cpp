#include <iostream>
#include <chrono>
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


int sumUpPisanoSequenceSquarredIndex(std::vector<long long> fib, long long PositionInSequence)
{
    int index = 0;
    int squared = fib[0];
    int sum = 0;

    //Printing results for control
    printPisanoSequence(fib);
    std::cout << "\n";

    while(index <= PositionInSequence)
    {
        squared = (fib[index]* fib[index]);
        sum = (sum + squared)%10;//Only keep last digit in sequence sum. Avoid digit > 10.
        std::cout << "+" << squared;
        index++;
    }

    std::cout << "\nTotal sum of squared is: " << squared << "\n";
    return sum;
}

int FastLastFibNumberSquarred(long long n)
{
    int moduloNb = 10;
    int result;

    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size();
    long long PositionInSequence = n % sequenceLength;

    result = sumUpPisanoSequenceSquarredIndex(PisanoArray, PositionInSequence);


    return result;
}

int main()
{

    long long Fib_n;
    
    std::cin >> Fib_n;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    int result = FastLastFibNumberSquarred(Fib_n);
    std::cout << "\nresult is : "<< result;

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "\nExecution time: " << duration.count() << " milliseconds\n";
}