#include "red_black_tree.hpp"

#include <iostream>
int main()
{
    RBT<int, std::string> s;
    s.insert(1);
    s.insert(0);
    s.insert(6);
    s.insert(2);
    std::cout << "Red black trees are cool"  << std::endl;
    s.print_tree();
    int b = 1;
    struct Node<int, std::string> * ptr = s.search(1);
    std::cout << ptr->color << std::endl;
    std::cout << ptr->key << std::endl;
    s.delete_element(6);
    s.print_tree();
}
