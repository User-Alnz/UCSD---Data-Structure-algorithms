#include <iostream>
#include <chrono>
#include <vector>

//Slower algo ---------------
int FibSum(std::vector<long long> fib)
{
    int index = 0;
    int sum = fib[0];

    while(index < fib.size())
    {
        sum+= fib[index];
        index++;
    }

    sum = sum%10;

    return sum;
}

int NaivelastDigitOfSumFib(int Fib_nb)
{
    int sum=1;
    int index=2;

    if(Fib_nb == 0)
    return 0;
    
    Fib_nb+=1; // start 0 does not account as first number
    std::vector<long long> fib ={0, 1};

    while(index < Fib_nb)
    {
        fib.push_back((fib[index-1]+fib[index-2])%10);
        sum+=fib[index];
        sum = sum%10;
        index++;
    } 

    //print(fib);
    return sum;
}
// -------------

// Faster Algo -------------

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

    //Printing results for control
    //printPisanoSequence(fib);
    //std::cout << "\n";

    while(index <= PositionInSequence)
    {
        sum += fib[index];
        sum = sum%10;//Only keep last digit in sequence sum. Avoid digit > 10.
        //std::cout << "+" << sum;
        index++;
    }

    //std::cout << "\nTotalSum is: " << sum << "\n";
    return sum;
}


int FastLastDigitOfSumFib(long long n)
{
    int moduloNb = 10;
    int result;

    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    long long sequenceLength = PisanoArray.size();
    long long PositionInSequence = n % sequenceLength;

    result = sumUpToPisanoSequenceIndex(PisanoArray, PositionInSequence);


    return result;
}

// ----------------------



void test()
{
    std::vector<long long> Fib_n {1, 0, 4, 115, 100, 450, 350, 30, 90};

    int index = 0;
    while(index < Fib_n.size())
    {
        std::cout << "------------------\n\nStart of TEST number => " << index+1 << "\n\n";

        std::cout << "Testing following Fibonacci number : " << Fib_n[index];

        auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

        int FastLastFibNumber = FastLastDigitOfSumFib(Fib_n[index]);
        
        auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationFastLastFibNumber = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        start = std::chrono::high_resolution_clock::now(); //Start catching exec time

        int NaivelastDigitOfFibSum = NaivelastDigitOfSumFib(Fib_n[index]);

        stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationNaivelastDigitOfFibSum = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        if(FastLastFibNumber == NaivelastDigitOfFibSum)
        {

            std::cout << "\n\nFastLastFibNumber is : " << FastLastFibNumber << " & NaivelastDigitOfFibSum is :" << NaivelastDigitOfFibSum;
            std::cout << "\n test Passed ! Ok\n";
                            
        }
        else
        {
            std::cout << "Wrong answer " << FastLastFibNumber << " != " << NaivelastDigitOfFibSum << "\n";
            std::cout << "Execution time of FastLastFibNumber is : " << durationFastLastFibNumber.count() << " milliseconds\n";
            std::cout << "Execution time of NaivelastDigitOfFibSum is : " << durationNaivelastDigitOfFibSum.count() << " milliseconds\n\n";
            break;
        }


       std::cout << "Execution time of FastLastFibNumber is : " << durationFastLastFibNumber.count() << " milliseconds\n";
       std::cout << "Execution time of NaivelastDigitOfFibSum is : " << durationNaivelastDigitOfFibSum.count() << " milliseconds\n\n";
        index++;
    }
}


int main()
{

    test();
}