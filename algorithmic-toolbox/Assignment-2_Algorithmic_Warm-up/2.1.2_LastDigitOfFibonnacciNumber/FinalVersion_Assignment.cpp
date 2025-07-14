#include <iostream>
#include <vector>

int LastDigitFibonnaci(int n)
{
    int index = 2;
    std::vector<int> fib = { 1, 1 };

    if( n == 0 )
    return 0;
        
    while(index < n)
    {
        fib.push_back((fib[index - 1] + fib[index -2])%10); //Just store last digit and sum up 
        index++;
    }
    
    return fib[index-1];
}

int main()
{
    int n;

    std::cin >> n;
    std::cout << LastDigitFibonnaci(n);
    return 0;
}