#include <iostream>
#include <vector>

// for n > 10ˆ6 we need more > 1s which is not allowed. iteration over all Fibonacci number to gues modulo is not optimum
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

int main()
{
    long long Fib_n;
    int moduloNb;

    std::cin >> Fib_n;
    std::cin >> moduloNb;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    int result = HugeFibNumber(Fib_n, moduloNb);
    std::cout << "Fib result is :" << result << "\n";

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}