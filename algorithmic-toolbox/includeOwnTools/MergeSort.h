#include <iostream>
#include <vector>
#include <functional> // for std::less, std::greater // functional lib => this return true or false. And help order ASC or DESC.

template<typename T>
class MergeSort {

    public :

        void sortASC(std::vector<T>& srcArray)
        {
            mergeSort(srcArray, std::less<T>()); //pass comp to pass it merge() method
        }
        
        void sortDesc(std::vector<T>& srcArray)
        {
            mergeSort(srcArray, std::greater<T>());
        }

        void mergePairFirstASC(std::vector<T>& srcArray) {
            mergeSort(srcArray, []( const T& a, const  T& b) { return a.first < b.first; });//pass comp as array on two pointer ref of reference arg entering type. retuning result of comparaision.
        }

        /*
            add here other methods.
            like mergePairASC()
        */
        

    private:

        /*
            template <typename Compare> is default function. used to inject sorting rules. 
            like std::less<T>(), std::greater<T>(), or custom rules ... 
        */

        template <typename Compare>
        void mergeSort(std::vector<T>& srcArray, Compare comp)
        {
            int length = srcArray.size();

            if(length <= 1) 
            return;


            int middle = length / 2;
            std::vector<T> leftArray(middle);
            std::vector<T> rigthArray(length - middle);

            int indexLeftArray = 0;
            int indexRightArray = 0;

            while(indexLeftArray < length)
            {
                if(indexLeftArray < middle)
                    leftArray[indexLeftArray] = srcArray[indexLeftArray];
                else
                {
                    rigthArray[indexRightArray] = srcArray[indexLeftArray];
                    indexRightArray++;
                }
                indexLeftArray++;
            }
            
            mergeSort(leftArray, comp);
            mergeSort(rigthArray, comp);

            merge(leftArray, rigthArray, srcArray, comp);
        }

        template <typename Compare>
        void merge(std::vector<T>& leftArray, std::vector <T>& rigthArray, std::vector<T> & srcArray, Compare comp)
        {
            int leftSize = (srcArray.size())/2;
            int rigthSize = (srcArray.size()) - leftSize;

            int index =0, leftIndex = 0, rigthIndex = 0;

            while(leftIndex < leftSize && rigthIndex < rigthSize)
            {
                if(comp(leftArray[leftIndex], rigthArray[rigthIndex]))
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
};