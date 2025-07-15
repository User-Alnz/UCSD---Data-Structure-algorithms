#include <iostream>
#include <chrono>
#include <vector>

void print(std::vector<long long> fib)
{
    int idx = 0;
    std::cout << "[";

    while(idx < fib.size())
    {
        std::cout << " " << fib[idx] << " ";
        idx++;
    }

    std::cout << "]";
}

int FibSum(std::vector<long long> fib)
{
    int index = 0;
    int sum = fib[0];

    while(index < fib.size())
    {
        sum+= fib[index];
        index++;
    }

    sum = sum%10;

    return sum;
}

int NaivelastDigitOfFibSum(int Fib_nb)
{
    int sum=1;
    int index=2;

    if(Fib_nb == 0)
    return 0;
    
    Fib_nb+=1; // start 0 does not account as first number
    std::vector<long long> fib ={0, 1};

    while(index < Fib_nb)
    {
        fib.push_back((fib[index-1]+fib[index-2])%10);
        sum+=fib[index];
        sum = sum%10;
        index++;
    } 

    print(fib);
    return sum;
}

int main()
{
    int Fib_n;
    

    std::cin >> Fib_n;

    auto start = std::chrono::high_resolution_clock::now(); //Start catching exec time 

    int result = NaivelastDigitOfFibSum(Fib_n);
    std::cout << "\nresult is : "<< result;

    auto stop = std::chrono::high_resolution_clock::now(); //Stop catching exec time 

     
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start); 
    std::cout << "\nExecution time: " << duration.count() << " milliseconds\n";
}