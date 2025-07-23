#include <vector>
#include <iostream>
#include <climits>
#include <algorithm>


/*
    algorithm 1 -----------

    WorkoutTotalWaitingTime()
    
    option 1) O(n²) if sortVectorAscOrder() is used in WorkoutTotalWaitingTime(). 
    option 2) but O( n log n ) if we use std::sort from <algorithm> in WorkoutTotalWaitingTime().

    this algo is much faster on large number inputs if option 2 but is slower than algo comming below (algorithm 2)
    on option 1 due to quadratic complexity of bubble sort / sortVectorAscOrder().

    ! algorithm 1 + option 2 is in reality the most optimum method between algorithm 1 + option 1 and algorithm 2 
    below. Because it reduces whole complexity from O(n²) to O(n log n ). And we do operate simple O(n) loop to 
    figure out totalWaitingTime. 
*/

void printVector(std::vector<int> vector)
{
    int idx = 0;
    std::cout << "[";

    while(idx < vector.size())
    {
        std::cout << " " << vector[idx] << " ";
        idx++;
    }

    std::cout << "]";
}

void swap(int & nb1, int & nb2)
{
    int temp; 

    temp = nb1; 
    nb1 = nb2;
    nb2 = temp; 
}

std::vector<int> sortVectorAscOrder(std::vector<int> vec) //bubble sort 
{
    
    for(int i = 0; i < vec.size()-1; i++)
    {
        for(int j = 0; j < vec.size()-1; j++)
        {
            if(vec[j] > vec[j+1])
                swap(vec[j], vec[j+1]);
        }
    }
    
    return vec;
}

int WorkoutTotalWaitingTime(std::vector<int> treatmentTimeCopy) // pass a copy 
{
    int waitingTime;
    int totalWaitingTime;

    waitingTime = 0;
    totalWaitingTime = 0;
        
    // OPTION 1 
    //std::vector<int> treatmentTime = sortVectorAscOrder(treatmentTimeCopy); O(n²)

    // OPTION 2 
    //sdt::sort is much perf than bubble sort //https://en.cppreference.com/w/cpp/algorithm/sort.html
    std::vector<int> treatmentTime = treatmentTimeCopy;
    std::sort(treatmentTime.begin(), treatmentTime.end()); //O(n log n)

    for (int i = 0; i < treatmentTime.size() - 1; i++)
    {
        waitingTime += treatmentTime[i];
        totalWaitingTime += waitingTime;
    }

    return totalWaitingTime;
}


/*
    algorithm 2 -----------

    minTotalWaitingTime()
    O(n²)

*/

int minTotalWaitingTime(std::vector<int> treatmentTime, int nbOfPatient)
{
    int index; 
    int minValue;
    int memoizedIndex;
    int waitingTime;
    std::vector<int> treated(nbOfPatient, 0);
    
    waitingTime = 0;
    while(treatmentTime.size())
    {

        index= 0;
        minValue = INT_MAX;
        memoizedIndex = 0;

        while(index < treatmentTime.size())
        {   
            if(treated[index] == 0 && treatmentTime[index] <= minValue)
            {
                minValue = treatmentTime[index];
                memoizedIndex = index;
            }
            index++;
        }

        nbOfPatient--;
        waitingTime += (nbOfPatient) * minValue;
        treated[memoizedIndex] = 1;

        std::cout << "\nnbOfPatient is :"<< nbOfPatient<<" \n";
        std::cout << "WaitingTime += (nbOfPatient-1) * minValue : "<< waitingTime << " = " << nbOfPatient << " * " << minValue << "\n";
        std::cout << "WaitingTime is  : "<< waitingTime <<"\n";
        std::cout << "\nList is now : \n";
        printVector(treatmentTime);std::cout << "\n";
        printVector(treated);
        std::cout << "\nLowest t time was  " << minValue << " \n";

        if(nbOfPatient == 1)
            break;

    }
    std::cout << "\n";
    return waitingTime;

}

int main()
{
    
    std::vector <int> treatmentTime = { 5, 8, 2, 9, 5 };
    //std::vector <int> treatmentTime = { 1, 6, 0, 9, 2 };
    
    
    int nbOfPatient = treatmentTime.size();

    int result = minTotalWaitingTime(treatmentTime, nbOfPatient);    
    int result2= WorkoutTotalWaitingTime(treatmentTime);

    std::cout << "\nTotal waiting time from function minTotalWaitingTime() is  => " << result << " \n";
    std::cout << "\nTotal waiting time from function WorkoutTotalWaitingTime() is => "<< result2 <<"\n";



}