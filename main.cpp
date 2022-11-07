#include "red_black_tree.hpp"

#include <iostream>
int main()
{
    RBT<int> s;
    s.insert(1);
    s.insert(0);
    s.insert(6);
    s.insert(2);
    std::cout << "Red black trees are cool"  << std::endl;
    s.print_tree();
    int b = 1;
    struct Node<int> * ptr = s.search(&b);
    std::cout << ptr->color << std::endl;
}