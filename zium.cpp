#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "map.hpp"
std::string * new_str (std::string &ref, std::allocator<std::string> alloc )
{
    std::string *ptr;
   
    ptr = alloc.allocate(1);
    alloc.construct(ptr, ref);
    return ptr;
}

int main()
{
    // ft::Map<int, std::string> map;
    std::map<int, std::string> mapp;
    std::map<int, std::string>::iterator s;
    ft::new_RBT<int, std::string> ss;
    ft::pair<int, std::string> d = ft::make_pair<int, std::string>(1, "Siemanko");
    ft::pair<int, std::string> dd = ft::make_pair<int, std::string>(-4, "Borys");
    ss.insert(d);
    ss.insert(dd);
    // s.insert(p1);
    // s.insert(p3);
    // s.insert(p2);
    // s.delete_val(p3);
    // s.delete_val(p1);
    // s.delete_val(p2);
    // int dddd = 1;
    int chuj = -4;
    std::cout << sizeof(ft::new_RBT<int, std::string>::value_type) <<std::endl;
    ss.print_tree();
    // ss.delete_val(dddd);
    ss.delete_val(chuj);
    std::cout << std::endl;
    ss.print_tree();
}