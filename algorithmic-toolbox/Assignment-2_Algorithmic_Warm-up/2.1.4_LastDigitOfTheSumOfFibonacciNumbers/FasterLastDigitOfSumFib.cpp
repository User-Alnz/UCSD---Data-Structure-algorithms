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

/* 
    Assuming Pisano sequence start from 0 and next start of sequence is 0 !
    just need to sum up from index 0 to position in sequence number to find out sum of last digit simply
*/

int sumUpToPisanoSequenceIndex(std::vector<long long> fib, long long PositionInSequence)
{
    int index = 0;
    int sum = fib[0];

    //Printing results for control
    printPisanoSequence(fib);
    std::cout << "\n";

    while(index <= PositionInSequence)
    {
        sum += fib[index];
        sum = sum%10;//Only keep last digit in sequence sum. Avoid digit > 10.
        std::cout << "+" << sum;
        index++;
    }

    std::cout << "\nTotalSum is: " << sum << "\n";
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

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    int result = FastHugeFibNumber(Fib_n);
    std::cout << "\nresult is : "<< result;

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "\nExecution time: " << duration.count() << " milliseconds\n";
}