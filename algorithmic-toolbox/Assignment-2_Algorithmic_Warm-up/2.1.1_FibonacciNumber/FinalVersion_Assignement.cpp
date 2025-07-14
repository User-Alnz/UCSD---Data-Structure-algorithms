#include <iostream>
#include <vector>

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

    return fib[index-1];
}

int main()
{
    int n;

    std::cin >> n;
    std::cout << FibonnacciList(n);
    return 0;
}