#include <iostream>
#include <vector>
#include <chrono>

// Faster Algo ------------------------------------------------------
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

    std::cout << "\n\tlast number is equal to : " << sum << "\n\n";
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

    // it's possible that m position is pisano seq is > n position n 
    // by chance sum of fibNumb(1) to f(59) is eqaul to 280 so modulo 10 there is no remainder
    // we then just need to sum up preSequence + PostSequence find out total sum because full PisanoSeqSum is =0
    int delta = ToPositionInSequence - FromPositionInSequence;
    if(delta < 0) 
    {
        int preSequence = sumUpInPisanoSequence(PisanoArray, FromPositionInSequence, sequenceLength-1);
        int postSequence = sumUpInPisanoSequence(PisanoArray, 0, ToPositionInSequence);
        // Mind that if we would work with full sequence we could create a variable sequence to store final modulo result and multiply it by times seq is repeated...
        result = (preSequence + postSequence)%10; // Avoid going futher than 10
        return result;
    }

    
    std::cout << "\n\tFor m Position in sequence is : " << FromPositionInSequence;
    std::cout << "\n\tFor n Position in sequence is : " << ToPositionInSequence << "\n\n";

    result = sumUpInPisanoSequence(PisanoArray, FromPositionInSequence, ToPositionInSequence);

    return result;
}

//------------------------------------------


// Slower Algo ------------------------------------------------------

void print(std::vector<long long> fib)
{
    int idx = 0;
    std::cout << "[";

    while(idx < fib.size())
    {
        std::cout << " " << fib[idx] << " ";
        idx++;
    }

    std::cout << "]";
}

int FibSum(std::vector<long long> fib, int Fib_m, int Fib_n)
{
    int index = Fib_m;//1; //= 0;
    int sum = fib[0];

    //index = Fib_m;
    int limit = Fib_n;

    while(index <= limit)//fib.size())
    {
        sum+= fib[index];
        std::cout << " + " << sum;
        index++;
    }
    std::cout<<"\n\nTotal sum is : " << sum;
    sum = sum%10;

    return sum;
}

int NaivelastDigitOfFibPartialSum(int Fib_m, int Fib_n)
{
    int sum;
    int index=1;

    //if(Fib_n == 0)
    //return 0;
    
    std::vector<long long> fib ={0, 1};

    while(index <= Fib_n)
    {
        fib.push_back((fib[fib.size()-1]+fib[fib.size()-2])%10);
        //sum+=fib[index];
        //sum = sum%10;
        index++;
    } 

    print(fib);
    sum = FibSum(fib, Fib_m, Fib_n);
    
    return sum;
}

//-------------------------------------------------------------------

void test()
{
    std::vector<long long> Fib_m {1, 0, 4, 50, 100, 100, 10, 90};
    std::vector<long long> Fib_n {5, 10, 121, 60, 110, 450, 10, 130};
    //std::vector<long long> Fib_m {4, 4, 4, 12 };
    //std::vector<long long> Fib_n {5, 4, 121, 122 };

    int index = 0;
    while(index < Fib_n.size())
    {
        std::cout << "------------------\n\nStart of TEST number => " << index+1 << "\n\n";

        std::cout << "Testing following Fibonacci number m : " << Fib_m[index] << " & n : " << Fib_n[index];

        auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

        int FastAlgo = FastLastDigitOfFibPartialSum(Fib_m[index], Fib_n[index]);
        
        auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationFastAlgo = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        start = std::chrono::high_resolution_clock::now(); //Start catching exec time

        int NaiveAlgo = NaivelastDigitOfFibPartialSum(Fib_m[index], Fib_n[index]);

        stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationNaiveAlgo = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        if(FastAlgo == NaiveAlgo)
        {

            std::cout << "\n\n FastAlgo is : " << FastAlgo << " & NaiveAlgo is :" << NaiveAlgo;
            std::cout << "\n test Passed ! Ok\n";
                            
        }
        else
        {
            std::cout << "\nWrong answer FastAlgo : " << FastAlgo << " != NaiveAlgo : " << NaiveAlgo << "\n";
            std::cout << "Execution time of FastAlgo is : " << durationFastAlgo.count() << " milliseconds\n";
            std::cout << "Execution time of NaiveAlgo is : " << durationNaiveAlgo.count() << " milliseconds\n\n";
            break;
        }


       std::cout << "Execution time of FastAlgo is : " << durationFastAlgo.count() << " milliseconds\n";
       std::cout << "Execution time of NaiveAlgo is : " << durationNaiveAlgo.count() << " milliseconds\n\n";
        index++;
    }
}

int main()
{
    test();
}