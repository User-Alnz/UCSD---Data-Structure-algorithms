#include <vector>
#include <iostream>

/*
    Start of helper function ! 

    printVector() =>  print result of best arrangement to find out maxSalary or Greatest concatanation of numb

    workOutGreaterDESCArrangment() => is comp function to find out greatest numb combination of 2 numb

        this is based on simple comparision of digits in number going recursively from log10(n); or digitLength(nbr).
        best arrangement of number is simple. it depends of digit making up numb. 

        like a = 26 and b = 65. "6526" is necessarly > than "2665" because first a digit 2 > b digit 6. And so on.
        
        this can be figure out using digitFromNumber()

    subfunction of workOutGreaterDESCArrangment()  => digitLength(nbr) & digitFromNumber(int numb, int position)

*/

void printVector(const std::vector<int> &vector)
{
    int idx = 0;
    while(idx < vector.size())
    {
        std::cout << vector[idx];
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
    return a;

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


            if(aDigit == bDigit)
            {
               aPosition --;
               bPosition --;
            }
            else if (aDigit > bDigit)
            return a; 
            else if(bDigit > aDigit)
            return b; 

        }
    }

    return a;
}

/*
    Solution is O(n² * c).  c is comparaison of numb in nested loop.

    but we retain O(n²)

    it can be simplified by using Merge sorting or quickSorting which are O(n log n)
    based based on comp O(n)  workOutGreaterDESCArrangment(int &a, int &b);

*/
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
                continue;
            }
            
            bestASCNumb = workOutGreaterDESCArrangment(bestASCNumb, digitList[index]);
            
            if(bestASCNumb != refNumber && treatedIndex[index] != 1)
            {
                refNumber = bestASCNumb;
                memoizedIndex = index;
            }

            index++;
        }

        treatedIndex[memoizedIndex] = 1;
        digitOrdered.push_back(digitList[memoizedIndex]);
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