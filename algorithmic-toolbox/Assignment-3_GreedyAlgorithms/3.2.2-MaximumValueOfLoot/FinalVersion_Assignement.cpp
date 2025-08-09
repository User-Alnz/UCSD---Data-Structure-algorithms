#include <vector>
#include <iostream>
#include <iomanip>

void workoutCostPerUnit(const std::vector<std::pair<int, int>>& costAndWeight,  std::vector<double>& costPerUnit )
{
    int index = 0;
    while(index < costAndWeight.size())
    {
        costPerUnit.push_back( static_cast<double>(costAndWeight[index].first) / costAndWeight[index].second);
        index++;
    }
}


double MaximumValueOfLoot( int backpackCapacity, std::vector<std::pair<int, int>>costAndWeight )
{

    std::vector<double> costPerUnit;
    std::vector<int> treatedIndex(costAndWeight.size(), 0);
    

    double unitMaximumCost = 0;
    int memoizedIndex = 0;
    int capacity = 0;
    double MaxValue = 0;


    workoutCostPerUnit(costAndWeight, costPerUnit);


    int index = 0;
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
        int itemWeight = costAndWeight[memoizedIndex].second;
        

        if(itemWeight <= backpackCapacity && (capacity + itemWeight) <= backpackCapacity )
        {
            MaxValue += unitMaximumCost * itemWeight;
            capacity += itemWeight; 
        }
        else
        {
            double remainingCapacity = backpackCapacity - capacity;
            MaxValue += remainingCapacity * unitMaximumCost;
            capacity += remainingCapacity;
        }

        if(capacity >= backpackCapacity || unitMaximumCost == 0)
        break;

    }

    return MaxValue;

}


int main()
{
    double result;
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

    result = MaximumValueOfLoot(backpackCapacity, costAndWeight);

    std::cout << std::fixed << std::setprecision(4) << result;
    
    return 0;
}