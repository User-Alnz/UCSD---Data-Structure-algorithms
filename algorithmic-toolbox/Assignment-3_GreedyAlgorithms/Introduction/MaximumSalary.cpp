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

//Is a quadratic function O(n^2) 
int maximumSalary(std::vector<int> digitList) //Pass it as a copy in parameter.
{

    int maxNumberInLoop;
    int memoizedIndex;
    int index;
    int result = 0;

    std::cout << "Assignement return biggest digit from list. List chosen : \n" ;
    printVector(digitList);
    //std::cout << digitList.size();
    std::cout << "\n\n";
    
    while(digitList.size()) // repeat until 0 element
    {

        maxNumberInLoop = digitList[0];
        memoizedIndex = 0;
        index = 0;
        
        std::cout << "Element(s) still in digitList : " << digitList.size()<< "\n";
        printVector(digitList);
        std::cout << "\n";

        while(index < digitList.size())
        {

            if(maxNumberInLoop < digitList[index])
            {
                maxNumberInLoop = digitList[index];
                memoizedIndex = index;
            }
            index++;
        }

        std::cout << "maxNumberInLoop is : " << maxNumberInLoop << " its index is " << memoizedIndex << "\n";
        result = result*10 + maxNumberInLoop; // add numb to result
        std::cout << "digitList.size()  is : " << digitList.size() << "\n";
        std::cout << "result is : " << result << "\n\n";

        digitList.erase(digitList.begin() + memoizedIndex);
        
    }

    return result;
}


int main()
{
    //Behave method only work on digit !  ex : [11, 3] return => 113 but greatest combination is 311.
    //Need find other method but was not in assignement.
    std::vector<int> digitList = {2, 3, 9, 1, 2};

    int maxSalary = maximumSalary(digitList);

    std::cout << "max Salary is : " << maxSalary;

}