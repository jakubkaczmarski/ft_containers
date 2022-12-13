#include "vector.hpp"
#include <vector>
int main()
{
    ft::vector<int> vec;
    std::vector<int> vec1;
    vec.push_back(12);
    vec.push_back(12321);
    vec.push_back(12321);
    vec1.push_back(12);
    vec1.push_back(12321);
    vec1.push_back(12321);
    ft::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it1 = vec1.begin(); 
    vec1.insert(it1, 123);
    vec.insert(it, 123);
    for(int i = 0; i < vec1.size(); i++)
    {
        std::cout << vec1[i] << std::endl;
    }
}