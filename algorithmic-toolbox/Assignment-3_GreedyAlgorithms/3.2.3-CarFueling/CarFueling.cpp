#include <vector>
#include <iostream>

/*
    This solution is O(n) in worst case. 
    Because O(n) is called on each "stop" to refill in first while loop. thus each time we move to next stop we go O(n)

    So it's like O(n) = O(n) + O(n) ... 

    Moreover by memoizing index we remove at least n-1 in worst case. 
    So it's at least O(n)= O(n-1) + O(n-1) ... 

    So it's time complexity is O(n). Though if each stop is each time at n+1 while iterating in stops list the worst case remain < O(n²), 
    because we would keep looping from next n+1 index. 
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