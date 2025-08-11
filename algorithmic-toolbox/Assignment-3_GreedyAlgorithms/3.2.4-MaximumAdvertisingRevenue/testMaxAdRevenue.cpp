#include <vector>
#include <iostream>
#include "MaxAdRevenue.h"

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

        maxAdRevenue += static_cast<long long>(maxClick) * maxPrice;

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

        // uncomment to track result in loop 
        //std::cout << maxPrice << " * " << maxClick << " = "<<  maxPrice*maxClick<<"\n";

        treatedPrice[memoizedMaxPriceIndex] = 1;
        treatedClicks[memoizedMaxClickIndex] = 1;

        if(maxPrice == 0  && maxClick == 0)
            areAllValuesParsed = true;

    }

    return maxAdRevenue;
}