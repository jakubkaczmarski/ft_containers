#include <iostream>
#include <string>
#include <memory>

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
    ft::map<int, std::string> map;
    // s.insert(p1);
    // s.insert(p3);
    // s.insert(p2);
    // s.delete_val(p3);
    // s.delete_val(p1);
    // s.delete_val(p2);
    // s.print_tree();
    
}