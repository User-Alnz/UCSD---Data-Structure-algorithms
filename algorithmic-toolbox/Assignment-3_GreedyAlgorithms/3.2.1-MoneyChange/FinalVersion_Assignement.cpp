#include <iostream>
#include <vector>

//time complexity is O(1) constant -> 3 operations each time it runs.
int moneyChange(int money) 
{
    
    int result = 0;

    result += (money/10);
    result += (money % 10 )/5;
    result +=  money %5;

    return result;
}

int main()
{

    int money;

    //denomintaion is described as follow in assignement 
    std::vector <int> denomination = {10, 5, 1};

    std::cin >> money;

    int minNumberOfChange = moneyChange(money);

    std::cout << minNumberOfChange ;
}