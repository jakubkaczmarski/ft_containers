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
    ft::map<int, int, std::plus<int> > mp3;
    ft::map<int, int>::iterator it = mp3.begin();
    if(!it.base()){}

       // ft::Map<int, std::string> map
    // std::map<int, std::string>::iterator s;
}