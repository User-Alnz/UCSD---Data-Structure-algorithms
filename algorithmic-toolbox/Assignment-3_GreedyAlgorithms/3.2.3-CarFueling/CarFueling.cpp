#include <vector>
#include <iostream>

/*
    This solution is O(n²) in worst case. Though by memoizing index we remove at least n-1 in worst case. 
    So running time is somewhere between O(n²) and O(n)
*/
int minimumNumberOfRefill(int distance, int gazTankMaxCapacity, int nbrOfStops, const std::vector <int>& stopsOnRoad)
{

    int currentPosition = 0;
    int index = 0;
    int memoizedIndex = 0;
    int MaxDistanceBeforeRunOutGaz = 0;
    int stop = 0;
    int minimumRefill = 0;

    while(currentPosition <= distance)
    {

        index = 0;
        stop =0;

        if(currentPosition == 0)
        MaxDistanceBeforeRunOutGaz = currentPosition + gazTankMaxCapacity;
        else
        MaxDistanceBeforeRunOutGaz = currentPosition;
        
        if(memoizedIndex > 0) //Avoid passing through indexes already parsed. 
        index = memoizedIndex+1;

        while(index < stopsOnRoad.size())
        {
            
            if(MaxDistanceBeforeRunOutGaz >= stopsOnRoad[index])
            {
                stop = stopsOnRoad[index];
                memoizedIndex = index; 
            }
            
            std::cout << currentPosition << " & " << stopsOnRoad[index] << "\n";

            index++;
        }

        currentPosition = stop + gazTankMaxCapacity; // update current position at stop + next futherest distance reachable

        std::cout << "you get stop at  : " << stopsOnRoad[memoizedIndex] << "\n";
        std::cout << "current max reachable position is : " << currentPosition << "\n\n\n";

        if(gazTankMaxCapacity > distance)
            return 0;
        else if(stop == 0)
            return -1;
        else
            minimumRefill++;
    }

    return minimumRefill;

}

int main()
{
    /*
        Constraints. 
        1 ≤ d ≤ 10⁵ (10^5) . 
        1 ≤ m ≤ 400. 
        1 ≤ n ≤ 300. 
        0 < stop1 < stop2 <...< stopn < d.

        this take 3 parameters 
        d = distance.
        m = miles. or gas tank capacity before refil.
        n = number of stop in list
        stop = an array of int between 0 and max d. 
        
        Assignemnet => Compute the minimum number of gas tank re-fills to get from one city to another.
    */

    int result;

    int distance;
    int gazTankMaxCapacity;
    int nbrOfStops;
    std::vector <int> stopsOnRoad;


    distance = 200;
    gazTankMaxCapacity = 250;
    nbrOfStops = 2;
    stopsOnRoad.insert(stopsOnRoad.end(), {100, 150});

    result = minimumNumberOfRefill(distance, gazTankMaxCapacity, nbrOfStops, stopsOnRoad);

    std::cout << "\nResult is : " <<result;

    return 0;   
}