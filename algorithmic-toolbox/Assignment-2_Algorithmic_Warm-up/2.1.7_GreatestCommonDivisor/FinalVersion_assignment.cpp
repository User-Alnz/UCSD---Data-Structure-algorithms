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

int main()
{
    int a; 
    int b; 

    std::cin >> a >> b;

    std::cout << EuclidGCD(a, b);
}