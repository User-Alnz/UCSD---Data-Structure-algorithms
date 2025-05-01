#include <iostream>
#include <vector>
#include <chrono>

long long FibonnacciList(int n)
{
    int index = 2;
    std::vector<long long> fib = { 1, 1 };

    if( n == 0 )
        return 0;
        
    while(index < n)
    {
        fib.push_back(fib[index - 1] + fib[index -2]);
        index++;
    }

    int loopTo = 0;
    while(loopTo < fib.size()){
       std::cout << " The " << loopTo+1 << " is the number " << fib[loopTo] << " of Fibonnaci List" << "\n";
       loopTo++;
    }
    
    std::cout << index;
    return fib[index-1];
}

int main()
{
    int Fib_n;

    std::cin >> Fib_n;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    long long result = FibonnacciList(Fib_n);

    std::cout << "Fib result is :" << result << "\n";

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}