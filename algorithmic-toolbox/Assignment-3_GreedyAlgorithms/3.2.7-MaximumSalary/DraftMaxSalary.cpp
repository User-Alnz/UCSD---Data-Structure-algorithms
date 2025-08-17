#include <vector>
#include <iostream>


void printVector(const std::vector<int> &vector)
{
    int idx = 0;
    while(idx < vector.size())
    {
        std::cout << vector[idx] << " ";
        idx++;
    }
}

int digitLength(int nbr)
{   
    if(nbr < 10 )
    return 1;

    return 1 + digitLength(nbr/10);
}

int max(int &a, int &b)
{
    if(a > b)
    return a;
    else
    return b;
}

int min(int &a, int &b)
{
    if(a < b)
    return a;
    else
    return b;
}

int powerOf10(int exp) 
{
    int result = 1;
    for (int i = 0; i < exp; i++) 
    {
        result *= 10;
    }
    return result;
}

int digitFromNumber(int numb, int position)
{
    return (numb/(powerOf10(position)))%10;
}


int workOutGreaterDESCArrangment(int &a, int &b)
{
    
    int aLength;
    int bLength;

    int aDigit;
    int bDigit;
    
    int aPosition;
    int bPosition;

    aLength = digitLength(a);
    bLength = digitLength(b);

    aPosition = aLength - 1;
    bPosition = bLength -1;

    int digitPosition = 0;
    int smallestLength; 

    if(a == b)
    return a;//return (a *powerOf10(bLength)) + b;

    if(aLength == 1 && bLength == 1)
    {
        return max(a, b);
    }
        
    if(aLength > 1 || bLength > 1)
    {
        smallestLength = min(aLength, bLength);

        while(digitPosition <= smallestLength)
        {
            aDigit = digitFromNumber(a, aPosition);
            bDigit = digitFromNumber(b, bPosition);

            //std::cout << "Length of a is  : " << aLength <<  "Length of b is : " << bLength << "\n";
            //std::cout << aDigit << "\n";
            //std::cout << bDigit << "\n";

            if(aDigit == bDigit)
            {
               aPosition --;
               bPosition --;
            }
            else if (aDigit > bDigit)
            return a; //return (a *powerOf10(bLength)) + b;//return a;
            else if(bDigit > aDigit)
            return b; // (b *powerOf10(aLength)) + a;//return b;

        }
    }

    return a; //return (a *powerOf10(bLength)) + b; //by default
}

std::vector <int> maxSalary(std::vector <int> &digitList)
{   

    std::vector <int> digitOrdered;
    std::vector <int> treatedIndex(digitList.size(),0);

    size_t digitListLength = digitList.size();
    int bestASCNumb = 0;
    int memoizedIndex = 0;    
    int refNumber = 0;
    int index = 0;
    

    while((int)digitOrdered.size() < digitListLength)
    {

        bestASCNumb = 0;
        refNumber = 0;
        memoizedIndex = 0;
        index = 0;

        while(index < digitListLength)
        {
            if (treatedIndex[index] ==1) 
            {
                index++;
                continue; //get back to top until value not treated and comp
            }

            bestASCNumb = workOutGreaterDESCArrangment(bestASCNumb, digitList[index]);
            
            if(bestASCNumb != refNumber)
            {
                refNumber = bestASCNumb;
                memoizedIndex = index;
            }

            //std::cout << "\n refNumber in loop is  => " << refNumber << "  & bestASCNumb is equal to "<<  bestASCNumb << "\n"; 

            index++;
        }

        treatedIndex[memoizedIndex] = 1;
        digitOrdered.push_back(digitList[memoizedIndex]);

        //printVector(treatedIndex); std::cout << "\n";
        //std::cout <<  " bestASCNumb  is =  " << refNumber << " and its index is " << memoizedIndex << "\n";
    }

    return digitOrdered; 
}

int main()
{
    int n;
    std::cin >> n;
    std::vector <int> digitList;

    for (int args = 0; args < n; args ++ )
    {
        int digit;
        std::cin >> digit;

        digitList.push_back(digit);
    }

    std::vector <int> ListOrderd = maxSalary(digitList);
    printVector(ListOrderd);

    return 0;
}