#include <vector>
#include <iostream>
#include <string>

void printVector(const std::vector<int> &vector)
{
    int idx = 0;

    while(idx < vector.size())
    {
        std::cout << vector[idx];
        idx++;
    }
}

bool largestConcatenate( const int & a,  const int & b)
{
    std::string str1 = std::to_string(a);
    std::string str2 = std::to_string(b);

    if(str1 + str2 > str2 + str1)
        return true;
    else
        return false;
}


void merge(std::vector<int> &leftArray, std::vector<int> &rigthArray, std::vector<int> &srcArray, bool (*compRule)(const int&, const int&))
{
    size_t leftSize = (srcArray.size())/2;
    size_t rigthSize = (srcArray.size()) - leftSize;

    int index =0, leftIndex = 0, rigthIndex = 0;

    while(leftIndex < leftSize && rigthIndex < rigthSize)
    {
        if(compRule(leftArray[leftIndex], rigthArray[rigthIndex]))
        {
            srcArray[index] = leftArray[leftIndex];
            index++;
            leftIndex++;
        }
        else
        {
            srcArray[index] = rigthArray[rigthIndex];
            index++;
            rigthIndex++;
        }
    }

    while(leftIndex < leftSize)
    {
        srcArray[index] = leftArray[leftIndex];
        index++;
        leftIndex++;
    }
    while(rigthIndex < rigthSize)
    {
        srcArray[index] = rigthArray[rigthIndex];
        index++;
        rigthIndex++;
    }

}

void mergeSortByMaxConcatenateNumb(std::vector<int> &srcArray)
{

    size_t ArrayLength = srcArray.size();

    if(ArrayLength <= 1)
    return;

    size_t middle = ArrayLength /2;
    std::vector<int> leftArray(middle);
    std::vector<int> rigthArray(ArrayLength - middle);

    size_t leftIndex = 0;
    size_t rigthIndex = 0;

    while(leftIndex < ArrayLength)
    {
        if(leftIndex < middle)
            leftArray[leftIndex] = srcArray[leftIndex];
        else
        {
            rigthArray[rigthIndex] = srcArray[leftIndex];
            rigthIndex++;
        }
        leftIndex++;
    }

    mergeSortByMaxConcatenateNumb(leftArray);
    mergeSortByMaxConcatenateNumb(rigthArray);

    merge(leftArray, rigthArray, srcArray, largestConcatenate);
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

    mergeSortByMaxConcatenateNumb(digitList); 
    printVector(digitList);

    return 0;
}