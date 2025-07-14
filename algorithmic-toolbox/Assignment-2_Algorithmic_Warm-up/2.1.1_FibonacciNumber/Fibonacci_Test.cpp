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
    
    //std::cout << index;
    return fib[index-1];
}

long long FibonnacciRecursive(int n)
{
    if(n < 2)
        return n;
    else
        return(FibonnacciRecursive(n-1)+FibonnacciRecursive(n-2));
}

void test()
{
    int n = 0;
    int limit = 45; // Constraint  0 < n < 45

    while (n <= limit)
    {
        long long FibonnaciListResult = FibonnacciList(n);
        long long FibonnacciRecursiveResult = FibonnacciRecursive(n);

        std::cout << "\nFor number : " << n << " FibonnaciListResult is : " << FibonnacciRecursiveResult << " & FibonnaciListResult is : " << FibonnaciListResult << "\n";

        if(FibonnaciListResult == FibonnacciRecursiveResult)
                std::cout << "Ok\n";
        else{
            std::cout << "Wrong answer " << FibonnaciListResult << " != " << FibonnacciRecursiveResult << "\n";
            break;
        } 

        n++;
    }
    
}

int main()
{
    test();
    return 0;
}