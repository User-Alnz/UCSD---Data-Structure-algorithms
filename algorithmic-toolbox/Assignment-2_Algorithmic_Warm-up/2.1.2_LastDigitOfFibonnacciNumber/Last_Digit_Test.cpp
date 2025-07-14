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

int LastDigitFibonnaciRecursive(int n)
{
    if(n < 2)
        return n;
    else
        return((LastDigitFibonnaciRecursive(n-1)+LastDigitFibonnaciRecursive(n-2))%10);
}

long long PrintFibonnacciNumber(int n)
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

void test()
{
    int n = 0;
    int limit = 45; // Constraint  0 < n < 45 

    while(n <= limit)
    {
        int LastDigit = LastDigitFibonnaci(n);
        int LastDigitRecursif = LastDigitFibonnaciRecursive(n);

        std::cout << "\nThe Fib number is => " << PrintFibonnacciNumber(n);
        std::cout << "\nFor number : " << n << " LastDigitFibonnaci(n); is : " << LastDigit << " & LastDigitFibonnaciRecursive(n); is : " << LastDigitRecursif << "\n";

        if(LastDigit == LastDigitRecursif)
                std::cout << "Ok\n";
        else{
            std::cout << "Wrong answer " << LastDigit << " != " << LastDigitRecursif << "\n";
            break;
        }
        n++;
    }
}


int main()
{
    /*
        int Fib_n;
        std::cin >> Fib_n;
    */

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 
    
    test();

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}