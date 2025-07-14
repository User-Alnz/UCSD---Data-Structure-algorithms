#include <iostream>
#include <vector>

/* 
    What Is Pisano Period ??

        Modulo (remainder digit) of fibonacci number are a sequence within Fibonacci next 
        Which means that moduloNb is repeating sequence like : 

        modulo of 3 : Fib(n)%3 is equal to following pattern 

        0 1 1 2 0 2 2 1 0 1 1 2 0 2 2 1 0 1 1 2 0  etc ..
        
        which can be also interpreted this way :  
       [0 1 1 2 0 2 2 1 ] [0 1 1 2 0 2 2 1 ] [0 1 1 2 0 2 2 1 ]

        modulo of 4 : Fib(n)%4 is equal to following pattern

        0 1 1 2 3 1 0 1 1 2 3 1 0 1 1 2 3 1 0 1 1 
       [0 1 1 2 3 1] [0 1 1 2 3 1] [0 1 1 2 3 1]

       So to find out length of Pisano period we just need to figure out where pattern [0 1] restart ! 
       Therefore,  PisanoPeriod length is in range between index 0 < n < beginingNextPatternIndex-2
        
*/

void printPisanoSequence(std::vector<int> PisanoArray)
{
    int idx = 0;
    std::cout << "[";

    while(idx < PisanoArray.size()-3)
    {
        std::cout << " " << PisanoArray[idx] << " ";
        idx++;
    }

    std::cout << "]";
}

std::vector<int> PisanoPeriodSequence(int moduloNb)
{

    int index = 2;
    std::vector<int> fib = { 0, 1 };

    while(true)
    {
        fib.push_back((fib[index - 1] + fib[index -2])%moduloNb);
            
            if((fib[index-2] == 0 && fib[index - 1] == 1 )&& index > 2) //The pattern to find out 
                return fib;

        index++;
    }
}

int HugeFibNumber(long long n, int moduloNb)
{

    std::vector<int> PisanoArray = PisanoPeriodSequence(moduloNb);

    // Optional use | 
    printPisanoSequence(PisanoArray);

    int sequenceLength = (PisanoArray.size())-2; // Do not take into account last two digits [0,1]. there begining of next pattern 

    int PositionInSequence = n % sequenceLength;

    //std::cout << "\nPosition is there in Sequence : " << PositionInSequence;

    return PisanoArray[PositionInSequence];
}

int main()
{
    long long Fib_n;
    int moduloNb;

    std::cin >> Fib_n;
    std::cin >> moduloNb;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    int result = HugeFibNumber(Fib_n, moduloNb);
    std::cout << "\nresult is : "<< result;

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "\nExecution time: " << duration.count() << " milliseconds\n";
}