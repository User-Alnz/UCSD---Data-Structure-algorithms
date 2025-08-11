#include <vector>
#include <iostream>

int maxAdRevenue(const std::vector<int> & price, const std::vector<int> & clicks)
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

    int maxAdRevenue = 0;

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

    int result;

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