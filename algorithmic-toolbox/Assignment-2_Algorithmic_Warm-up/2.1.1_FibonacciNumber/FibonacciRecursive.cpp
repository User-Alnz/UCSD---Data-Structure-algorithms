#include <iostream>
#include <chrono>

long long stackCalls;

int FibonnaciRecursive(int n)
{
    //To display all iteration in tree until it find root to reconstitue from n1 + n2 || with n1 = 0 and n2 = 1
    //std::cout << n << "\n";

    stackCalls++; // All the times we need to itarate a new tree branch to find out root including all call to reconsitute F(n) | 
    //exemple For F(n) : 12 => Result is : 144 for 465 FibonnaciRecursive calls

    if(n < 2)
        return n;
    else
        return(FibonnaciRecursive(n-1)+FibonnaciRecursive(n-2));
}

int main()
{
    int Fib_n; // The fourth number in a row within Fibonacci next

    std::cin >> Fib_n;

    std::cout << "For F(n) : " << Fib_n << "\n";;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Result is : " << FibonnaciRecursive(Fib_n) << "\n";
    auto stop = std::chrono::high_resolution_clock::now();
    
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);

    std::cout << "Total recursive calls: " << stackCalls << "\n";
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}