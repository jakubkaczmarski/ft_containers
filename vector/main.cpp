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
    std::vector<int>::iterator it = vec.begin();
    std::vector<int>::iterator it_e = vec.end();
    ft::vector<int> ft(4, 3);
    ft::vector<int>::iterator c = ft.begin();
    std::cout << *c << std::endl;
    c++;
    std::cout << *c << std::endl;
    
    // ft.begin();
    // vec.reserve(12);
    // ft::vector<int> ft_vec(vec.begin(), vec.end());
    // ft_vec.print_all();
    // for(int i = 0; i < vec.size(); i++)
    // ft_vec.print_all();
    // for(int i = 0; i < vec.size(); i++)
    // {
    // std::cout << vec[i] << std::endl;
    // }
    // auto it = vec.begin();
    // int *animals;
    // ft::vector<int> vec;
    // std::cout << vec[1] << std::endl;
}
