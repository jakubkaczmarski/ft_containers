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
    ft::Map<int, int>::iterator it;

    it->first = 1;

    return (0);
       // ft::Map<int, std::string> map
    std::map<int, std::string>::iterator s;
}