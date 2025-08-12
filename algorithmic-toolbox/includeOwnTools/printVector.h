#include <iostream>
#include <vector>

class OutputArray {

    public:

        static void printVector(std::vector<int> vector)
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

        static void printVectorPair(std::vector <std::pair<int, int>> & vector)
        {
            int idx = 0;
            std::cout << "[";

            for(const auto& index : vector) 
            {
                std::cout << " { " << index.first << " , " << index.second << " } ";
                idx++;
            }

            std::cout << "]";
        }

};