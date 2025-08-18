#include <vector>
#include <iostream>
#include <string> // for string and to_string()

void printVector(const std::vector<int> &vector)
{
    int idx = 0;

    std::cout << "[";

    while(idx < vector.size())
    {
        std::cout << " "<< vector[idx] << " ";
        idx++;
    }

    std::cout << "]";
}


/*
    bool largestConcatenate( const int & a,  const int & b) // scan copy of a and b ref

    This is is lexicographic by ASCII,
    this compare each index of char in string form its ASCII value like : 

    ASCII  Table :
    char | int
    '0' → 48  
    '1' → 49  
    '2' → 50  
    '3' → 51  
    '4' → 52  
    '5' → 53  
    '6' → 54  
    '7' → 55  
    '8' → 56  
    '9' → 57

    exemple a = 56 & b = 54

    a+b => "56" + "54" = "5654" = [53, 54, 53, 52] 
    b+a => "54" + "56" = "5456" = [53, 52, 53, 54]
                                       |
                                    54 > 52
    => a + b > b + a
        return true ! 
    
    LargestConcatenate is a + b


*/

// this is O(n)
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
        if(compRule(leftArray[leftIndex], rigthArray[rigthIndex])) //comp is pointer on largestConcatenate(a, b)
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

/*
    By sorting element big largestConcatenate Time complexitiy is O(n log n * c)

    Sort by O(n log n) and merge is O(n * c)
    So time complexity is O(n log n *c) in worst case.
*/
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

    //this is O(n log n)
    mergeSortByMaxConcatenateNumb(digitList); 
    printVector(digitList);

    return 0;
}