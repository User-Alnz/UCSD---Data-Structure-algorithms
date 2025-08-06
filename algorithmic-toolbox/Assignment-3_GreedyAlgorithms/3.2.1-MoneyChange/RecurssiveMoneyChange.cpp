#include <iostream>
#include <vector>

int moneyChange(int money, std::vector<int> denomination)
{
    
    int maxCoins = 0; 
    
    if(money == 0) // catch if money is equal to 0. then no change possible
    return maxCoins; 

    for(int coins : denomination)
    {
        if(coins <= money)
        {
            // "1 +" return each instance call of money - coins & repeat until coins is equal or inf to money.
            return 1 + moneyChange(money - coins, denomination);
        }
    }

    return 0; // default return 
}

int main()
{

    int money = 28;
    std::vector <int> denomination = {10, 5, 1};

    int max = moneyChange(money, denomination);

    /*
        important to sort array "denomination" if is not. 

        How it works under the hood during recurive call =>
        moneyChange(28, denomination)
            
            Call for loop  
            → moneyChange(18)  // return 1 (28 -10)
             → moneyChange(8)  // return 1 (18 -10)
              → moneyChange(3)  // return 1  coins is < money. loop to => 5; (8 - 5 )
               → moneyChange(2)  // return 1 coins is < money. loop to => 1; (3-1)
                → moneyChange(1)  // return 1 (2 -1)
                 → moneyChange(0)  // return 1 (1-1) coins is < money. Exit loop; 

        total return +1 is equal to 6 operations 
        28 = 10 + 10 + 5 + 1 + 1 + 1 
        for a minimum number of change => 6 
    */

    std::cout << "resut is :" << max ;
}