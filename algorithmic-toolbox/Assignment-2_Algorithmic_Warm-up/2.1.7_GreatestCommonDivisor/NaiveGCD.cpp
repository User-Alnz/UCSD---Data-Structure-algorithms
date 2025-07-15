#include <iostream>


int NaiveGCD(int a, int b)
{
    int greatest;
    int commonDenominator = 1; 

    while(commonDenominator <= (a+b))
    {

        if((a % commonDenominator == 0 )&& (b % commonDenominator == 0))
        greatest = commonDenominator;

        commonDenominator++;
    }

    return greatest;
}

int main()
{
    int a;
    int b;

    std::cin >> a;
    std::cin >> b;

    std::cout << "\n" << NaiveGCD(a, b);
}