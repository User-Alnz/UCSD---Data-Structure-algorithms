#include <iostream>
#include <vector>

int moneyChange(int money, std::vector <int> denomination )
{
    int result = (money/10);

    std::cout << "money /10 = " << result << "\n";

    result = (money % 10 )/5;
    std::cout << "money mod 10 /5 = " << result << "\n";

    result =  money %5;
    std::cout << " money %5 = " << result << "\n";

    return (money/10) + ((money % 10 )/5) + (money % 5);
}

int main()
{

    int money = 28;
    std::vector <int> denomination = {10, 5, 1};

    int max = moneyChange(money, denomination);


    std::cout << "resut is :" << max ;
}