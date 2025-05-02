#include <iostream>
#include <vector>
#include <chrono>
#include <string>

/*
if need to print large number
std::string printNumber(__int128 numb )
{
    if(numb == 0)
    return "0";

    std::string numbAsString;
    while(numb > 0)
    {
        numbAsString =  char(48 + (numb%10)) + numbAsString; //Based on tab ASCII to write number as string not number | char 48 = "0", char 49 = "1" etc .. to 9.
        numb = numb /10;
    }

    return numbAsString;
} 
*/

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
    int Fib_n;

    std::cin >> Fib_n;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    long long result = LastDigitFibonnaci(Fib_n);

    std::cout << "Fib result is :" << result << "\n";

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "Execution time: " << duration.count() << " milliseconds\n";
}