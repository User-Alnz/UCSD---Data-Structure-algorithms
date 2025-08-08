#include <vector>
#include <iostream>
#include <iomanip>


/*
    To maximize loot the idea is to get as much as possible from most valuable item and get a fraction of the last highest value/unit. 
    This way we output the Maximum value by priorizing greastest value per unit.

    Following algo is O(n²) but can be improved by sorting using descending method O(n log n).
    this could also be O(n) but in asymptomatic notation we retain only wort case for n. So it's O(n²)

*/

float MaximumValueOfLoot( int backpackCapacity, std::vector<std::pair<int, int>>costAndWeight )
{

    int index = 0;

    std::vector<float> costPerUnit;
    std::vector<int> treatedIndex(costAndWeight.size(), 0);
    std::cout << std::fixed << std::setprecision(4);// this is from library <iomanip> to print float. std::cout cut decimal by default.


    float unitMaximumCost = 0;
    int memoizedIndex = 0;

    int capacity = 0;
    float MaxValue = 0;


    while(index < costAndWeight.size())
    {
        costPerUnit.push_back( static_cast<float>(costAndWeight[index].first) / costAndWeight[index].second); //type cast int/int to float
        index++;
    }

    for( auto item : costPerUnit)
    {
        std::cout << "Cost per unit is: " << item << "\n";
    }


    index = 0;
    while(capacity != backpackCapacity)
    {

        index = 0;
        unitMaximumCost = 0;
        while(index < costAndWeight.size())
        {
            if(costPerUnit[index] > unitMaximumCost && treatedIndex[index] == 0)
            {
                unitMaximumCost = costPerUnit[index];
                memoizedIndex = index;
            }
                
            index ++;
        }
        
        treatedIndex[memoizedIndex] = 1;
        

        if(costAndWeight[memoizedIndex].second <= backpackCapacity && (capacity + costAndWeight[memoizedIndex].second) <= backpackCapacity )
        {
            MaxValue += unitMaximumCost * costAndWeight[memoizedIndex].second;
            capacity += costAndWeight[memoizedIndex].second; 
        }
        else
        {
            float remainingCapacity = backpackCapacity - capacity;
            MaxValue += remainingCapacity * unitMaximumCost;
            capacity += remainingCapacity;
        }


        std::cout <<"\nUnitMaximumCost  : " <<  unitMaximumCost << "\n";
        std::cout <<"backpackCapacity  is :  " << backpackCapacity << " capacity is : " << capacity << "\n" ;
        std::cout <<"Result of maxValue : " << MaxValue << "\n";

        if(capacity >= backpackCapacity || unitMaximumCost == 0)
        break;

    }

    return MaxValue;

}


int main()
{
    float result;
    int numberOfCoumpounds;
    int backpackCapacity;

    std::cin >> numberOfCoumpounds;
    std::cin >> backpackCapacity;

    std::vector < std::pair <int, int>> costAndWeight;

    for(int agrs=0; agrs < numberOfCoumpounds; agrs++)
    {
        int cost, weight;

        std::cin >> cost >> weight;
        costAndWeight.push_back({cost, weight});   
    }

    for(const auto& item : costAndWeight)
    {
        std::cout << "Cost: " << item.first << ", Weight: " << item.second << "\n";
    }

    std::cout << "\n\n\n";

    result = MaximumValueOfLoot(backpackCapacity, costAndWeight);

    std::cout << "\n\n\n result is : " << result;
    return 0;
}