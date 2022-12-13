#include "vector.hpp"

int main()
{
    ft::vector<int> vec;
    vec.push_back(12);
    vec.push_back(12321);
    vec.push_back(12321);
    for(int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << std::endl;
    }
}