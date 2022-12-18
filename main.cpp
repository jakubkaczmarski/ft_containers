#include "vector.hpp"
#include <vector>
// #include "rbt_iter.hpp"
#include "test.hpp"

int main()
{
    // ft::rbt<int, int> s;
    ft::vector<int> vec;
    std::vector<int> vec1;
    vec.push_back(12);
    vec.push_back(12321);
    vec.push_back(12321);
    vec1.push_back(12);
    vec1.push_back(12321);
    vec1.push_back(12321);
    ft::vector<int>::iterator it = vec.begin();
    // vec1.insert(it1, 123);
    std::vector<int>::iterator it1 = vec1.begin(); 
    vec.insert(it, 123);
    ft::RBT<int, std::string> c;
    // ft::rbt_iterator<node, ft::RBT<int, std::string> > s;
    // for(int i = 0; i < vec1.size(); i++)
    // {
        // std::cout << vec1[i] << std::endl;
    // }
}