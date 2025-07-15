#include <iostream>

/*
    About GCD. the greatest common divider is a', the remainder of a/b as soon as b/remainder or b/a' is also equal to 0.
*/
int EuclidGCD(int a, int b)
{
    int greatest;
    int remainder;
    
    if(b==0)
    return a;
    else
    {  
        remainder = a%b;
        std::cout << "\nNew Step a EuclidGCD(b, remainder); is b = " << b << " And a' or remainder is : " << remainder; 
        return EuclidGCD(b, remainder);
    }

}

int main()
{
    int a; //3918848
    int b; //1653264

    std::cin >> a >> b;

    std::cout << "\n" << EuclidGCD(a, b);
}