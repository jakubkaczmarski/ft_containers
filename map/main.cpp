#include "red_black_tree.hpp"
#include <map>
#include <iostream>
#include <iterator>
#include "RedBlackTreeIterator.hpp"
int main()
{

    //Red black tree iterator
    //
    std::map<int, std::string> mapp;
    RBT<pair<int, std::string> > siemnako;
    // sie
    pair<int, std::string> s =  make_pair<int, std::string>(1, "Zlomek");
    std::cout << s.first << " | " << s.second << std::endl;
    RBT<pair<int, std::string> > custom_map;
    custom_map.insert(s);
    // mapp.insert(make_pair<int, std::string>(2, "Siemanko"));
    // std::map<int, std::string>::iterator iter_map = mapp.begin();
    // std::cout << (*iter_map).first << std::endl;
    // // int b;
    // RBT<int, std::string> s;
    // s.insert(1);
    // s.insert(0);
    // s.insert(6);
    // s.insert(2);
    // // s.
    // std::cout << "Red black trees are cool"  << std::endl;
    // s.print_tree();
    // int/search b = 1;
    // struct Node<int, std::string> * ptr = s.search(1);
    // std::cout << ptr->color << std::endl;
    // std::cout << ptr->key << std::endl;

    // s.delete_element(6);
    // s.print_tree();
}
