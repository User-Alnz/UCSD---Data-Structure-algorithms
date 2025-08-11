#include <vector>
#include <iostream>
#include "CarFueling.h"


int minimumNumberOfRefill(int distance, int gazTankMaxCapacity, int nbrOfStops, const std::vector <int>& stopsOnRoad)
{

    int currentPosition = 0;
    int index = 0;
    int memoizedIndex = 0;
    int MaxDistanceBeforeRunOutGaz = 0;
    int stop = 0;
    int minimumRefill = 0;


    if(gazTankMaxCapacity > distance)
    return 0;

    while(currentPosition <= distance) 
    {
        index = 0;
        stop = 0;

        MaxDistanceBeforeRunOutGaz = currentPosition + gazTankMaxCapacity;

        if(MaxDistanceBeforeRunOutGaz >= distance)
        return minimumRefill;
        
        if(memoizedIndex > 0)
        index = memoizedIndex+1;

        while(index < stopsOnRoad.size())
        {
            if(MaxDistanceBeforeRunOutGaz >= stopsOnRoad[index])
            {
                stop = stopsOnRoad[index];
                memoizedIndex = index; 
            }
            
            index++;
        }

        currentPosition = stop;

        if(stop == 0)// means if no stop found 
            return -1;
        else
            minimumRefill++;
    }

    return minimumRefill;
}