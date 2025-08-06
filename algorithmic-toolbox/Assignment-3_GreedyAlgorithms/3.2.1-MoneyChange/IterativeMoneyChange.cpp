#include <iostream>
#include <vector>

int moneyChange(int money, std::vector <int> denomination )
{
    int index = 0;
    int minNumberOfChange = 0; 

    while(money > 0)
    {
        std::cout << money << " - " << denomination[index] << "\n";
        if(denomination[index] <= money)
        {
            money -= denomination[index];
            minNumberOfChange++;
        }
        else
            index++;

    }

    return minNumberOfChange;
}

int main()
{

    int money = 2244556;
    std::vector <int> denomination = {10, 5, 1};

    int max = moneyChange(money, denomination);


    std::cout << "resut is :" << max ;
}