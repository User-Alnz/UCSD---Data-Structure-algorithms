#include <vector>
#include <iostream>


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

        if(stop == 0)
            return -1;
        else
            minimumRefill++;
    }

    return minimumRefill;
}

int main()
{

    int result;

    int distance;
    int gazTankMaxCapacity;
    int nbrOfStops;
    std::vector <int> stopsOnRoad;


    std::cin >> distance;
    std::cin >> gazTankMaxCapacity;
    std::cin >> nbrOfStops;
    
    for(int args = 0; args < nbrOfStops; args++)
    {
        int stop;
        std::cin >> stop; 
        
        stopsOnRoad.push_back(stop);
    }

    result = minimumNumberOfRefill(distance, gazTankMaxCapacity, nbrOfStops, stopsOnRoad);

    std::cout << result;

}