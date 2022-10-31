#include "random_access_it.hpp"
#include <string>
#include <iostream>
#include <iterator>
#include "vector.hpp"
#include <vector>


int main()
{
    std::vector<int> vec;
    vec.push_back(12);
    vec.push_back(32);
    vec.push_back(11);
    vec.push_back(154);
    // vec.reserve(12);
    ft::vector<int> ft_vec(vec.begin(), vec.end());
    ft_vec.print_all();
    // for(int i = 0; i < vec.size(); i++)
    ft_vec.print_all();
    // for(int i = 0; i < vec.size(); i++)
    // {
        // std::cout << vec[i] << std::endl;
    // }
    // auto it = vec.begin();
    // int *animals;
    // ft::vector<int> vec;
    // std::cout << vec[1] << std::endl;



}

