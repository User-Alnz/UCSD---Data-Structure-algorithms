#include <iostream>
#include <vector>

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


void WorkoutTotalWaitingTime(std::vector<int> treatmentTime) // pass a copy 
{
    int waitingTime;
    int totalWaitingTime;

    waitingTime = 0;
    totalWaitingTime = 0;
        
    //Does not account treatment time of last patient because it's the last. treatmentTime.size() - 1
   for (int i = 0; i < treatmentTime.size() - 1; i++)
    {
        waitingTime += treatmentTime[i];
        totalWaitingTime += waitingTime;
    }

    std::cout << "\nList is now : \n";
    printVector(treatmentTime);
    std::cout << "\nTotal waiting time  =>" << totalWaitingTime << " min\n";      
}


int main()
{

    /*
        For given list of patient having t time being time of treatement. 
        What is the best arrangement to obtain lowest totalWaitingTime ? 
        
        Should we treat each patient in ASC or DESC order of treatement time ?  Or AVG ? 

        If we have p patient = TreatementTimeOrderList.length().
        Which patient should we treat first depending their treatment time in Queue structure. 
        
        Such as for list like [ 5, 10, 20, 10] =>

        p1 = 0; //because first patient is treated first. thus waiting time is 0.  
        p2 = 5;
        p3 = 5 + 10; or 15
        p4 = 15 + 20; or p1 + p2 + p3; 

        totalWaitingTime is thus equal to 35 min.

        Below is the proof of concept that treating patient with the lowest t time first is the optimal queue arrangement for treatment. 
    */
    
    std::vector <int> treatmentTimeDESC = {9, 8, 5, 5, 2};
    std::vector <int> treatmentTimeASC = {2, 5, 5, 8, 9};
    std::vector <int> treatmentTimeNoneOrdered = { 5, 8, 2, 9, 5 };

    std::cout << "\n---------\nDesc ordered list test : \n";
    WorkoutTotalWaitingTime(treatmentTimeDESC);
    std::cout << "\n---------\nASC ordered list test : \n";
    WorkoutTotalWaitingTime(treatmentTimeASC);
    std::cout << "\n---------\nNone ordered lis test : \n";
    WorkoutTotalWaitingTime(treatmentTimeNoneOrdered);

    /*
        Output => 
        ---------
        Desc ordered list test : 

        List is now : 
        [ 9  8  5  5  2 ]
        Total waiting time  =>75 min

        ---------
        ASC ordered list test : 

        List is now : 
        [ 2  5  5  8  9 ]
        Total waiting time  =>41 min

        ---------
        None ordered lis test : 

        List is now : 
        [ 5  8  2  9  5 ]
        Total waiting time  =>57 min

    */
}