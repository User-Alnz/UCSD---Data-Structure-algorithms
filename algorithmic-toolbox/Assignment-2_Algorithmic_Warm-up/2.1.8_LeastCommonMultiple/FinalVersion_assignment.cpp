#include <iostream>

int EuclidGCD(int a, int b)
{
    int greatest;
    int remainder;
    
    if(b==0)
    return a;
    else
    {  
        remainder = a%b;
        return EuclidGCD(b, remainder);
    }

}

long long LeastCommonMutliple(long long a,  long long b)
{
    long long  result; 
    long long product = a * b; 
    int  gcd = EuclidGCD(a, b);

    result = product / gcd;

    return result;
}


int main()
{
    long long a; 
    long long b;

    std::cin >> a;
    std::cin >> b;

    std::cout << LeastCommonMutliple(a, b);
}