#include <iostream>
#include <vector>

class OutputArray {

    public:

        //[ 6 ,7, 1 ]
        static void printVector(const std::vector<int> &vector)
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

        // [ {1, 5 }, {5, 1} ]
        static void printVectorPair(const std::vector <std::pair<int, int>> & vector)
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

        // [ {1, 6 , 5 }, {5, 7, 1} ]
        static void print2DVector(const std::vector<std::vector<int>>& vectors)
        {
            std::cout << "[";
            for (const auto& v : vectors) 
            {
                std::cout << "{ ";
                for (auto x : v) std::cout << x << " ";
                std::cout << "} ";
            }
            std::cout << "]";
        }

};