#include <vector>
#include <iostream>

/*
    The solution below is O(n²). 
    It does loop through all values until it works out the total sum of product of greatest price * greatest clicks. 

    A faster solution would be to sort by O(n log n) price & clicks in DESC order.
    So that we just need to go O(n) by multiplying each upcoming index of Price * Clicks.
    
    Why not doing this here ? Simply because topic is comming later in course 
    + it would be cheating to use ::sort() method from vector. Because goal is to learn datastructure and its manipulation using logic. 

*/

long long maxAdRevenue(const std::vector<int> & price, const std::vector<int> & clicks)
{
    bool areAllValuesParsed = false;
    std::vector <int> treatedPrice(price.size(), 0);
    std::vector <int> treatedClicks(clicks.size(), 0);

    int index = 0;
    int arrayLength = price.size();

    int maxPrice = 0;
    int maxClick = 0;
    int memoizedMaxPriceIndex = 0;
    int memoizedMaxClickIndex = 0;

    long long maxAdRevenue = 0;

    while(areAllValuesParsed != true)
    {

        maxAdRevenue += maxClick * maxPrice;

        index = 0;
        maxPrice = 0;
        maxClick = 0;

        while(index < arrayLength)
        {

            if(maxPrice <= price[index] && treatedPrice[index] == 0)
            {
                maxPrice = price[index];
                memoizedMaxPriceIndex = index;
            }
            
            if(maxClick <= clicks[index] && treatedClicks[index] == 0)
            {
                maxClick = clicks[index];
                memoizedMaxClickIndex = index;
            }

            index ++;
        }

        std::cout << maxPrice << " * " << maxClick << " = "<<  maxPrice*maxClick<<"\n";

        treatedPrice[memoizedMaxPriceIndex] = 1;
        treatedClicks[memoizedMaxClickIndex] = 1;

        if(maxPrice == 0  && maxClick == 0)
            areAllValuesParsed = true;

    }

    return maxAdRevenue;
}


int main()
{
    /*
    Constraints. 1 ≤ n ≤ 10^3 ; 
    0 ≤ price(i), clicks(i) ≤ 10^5 for all 1 ≤ i ≤ n.

    price and clicks are always same size length of arguments 
    */

    long long result;

    int slotsAvailable; // i 
    std::vector <int> price;
    std::vector <int> clicks;

    std::cin >> slotsAvailable;

    
    for(int args = 0; args < slotsAvailable; args++)
    {
        int priceBid;
        std::cin >> priceBid; 
        
        price.push_back(priceBid);
    }

    for(int args = 0; args < slotsAvailable; args++)
    {
        int clickAvg;
        std::cin >> clickAvg; 
        
        clicks.push_back(clickAvg);
    }

    result = maxAdRevenue(price, clicks);

    std::cout << result;

}