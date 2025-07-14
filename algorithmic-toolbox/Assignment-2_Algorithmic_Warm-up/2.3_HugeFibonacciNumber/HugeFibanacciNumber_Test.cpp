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

// Faster Algo -----------
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
                fib.pop_back();//remove last index -1
                fib.pop_back();//remove index -2 
                return fib; // return a clean vector by removing last index in array [0, 1] which is the new start of pisano next
            }
        
        index++;
    }
}

int FastHugeFibNumber(long long n, int moduloNb)
{
    std::vector<long long> PisanoArray = PisanoPeriodSequence(moduloNb);

    printPisanoSequence(PisanoArray);

    long long sequenceLength = PisanoArray.size();

    long long PositionInSequence = n % sequenceLength;
    std::cout<< "\n\n n is " << n << "  moduloNb is  "<< moduloNb <<"\n";
    std::cout<< "\n position in sequence is " << PositionInSequence << "\n\n";

    return PisanoArray[PositionInSequence];
}
//----------


// Slower Algo -----------
int HugeFibNumber(long long n, int moduloNb)
{
    int index = 2;
    std::vector<int> fib = { 1, 1 };

    if( n == 0 )
    return 0;
        
    while(index < n)
    {
        fib.push_back((fib[index - 1] + fib[index -2])%moduloNb);
        index++;
    }
    
    return fib[index-1];
}
//----------

void test( )
{
    //Constraint  Fib_n = 1 < n < 10ˆ14
    //Constraint  moduloNb = 2 < n < 10ˆ3
    
    std::vector<long long> Fib_n {1, 115, 2816213588, 450, 3500, 8371946203};
    std::vector<int> moduloNb {239, 1000, 239, 5, 8, 10, };

    int index = 0;
    while(index < Fib_n.size())
    {

        std::cout << "------------------\n\nStart of TEST number => " << index+1 << "\n\n";

        auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

        int FastFibHugeNumb = FastHugeFibNumber(Fib_n[index], moduloNb[index]);
        
        auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationFastFibHugeNumb = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        

        start = std::chrono::high_resolution_clock::now(); //Start catching exec time

        int NaiveFibHugeNumb = HugeFibNumber(Fib_n[index], moduloNb[index]);

        stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 
        auto durationNaiveFibHugeNumb = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

        if(FastFibHugeNumb == NaiveFibHugeNumb)
        {

            std::cout << "\n\nFastHugeFibNumber is : " << FastFibHugeNumb << " & HugeFibNumber is :" << NaiveFibHugeNumb;
            std::cout << "\n test Passed ! Ok\n";
                            
        }
        else
        {
            std::cout << "Wrong answer " << FastFibHugeNumb << " != " << NaiveFibHugeNumb << "\n";
            std::cout << "Execution time of FastFibHugeNumb is : " << durationFastFibHugeNumb.count() << " milliseconds\n";
            std::cout << "Execution time of NaiveFibHugeNumb is : " << durationNaiveFibHugeNumb.count() << " milliseconds\n\n";
            break;
        }


       std::cout << "Execution time of FastFibHugeNumb is : " << durationFastFibHugeNumb.count() << " milliseconds\n";
       std::cout << "Execution time of NaiveFibHugeNumb is : " << durationNaiveFibHugeNumb.count() << " milliseconds\n\n";

        index++;
    }
     
}


int main()
{
    test();
    return 0;
}
