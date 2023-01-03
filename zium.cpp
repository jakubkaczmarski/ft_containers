#include <iostream>
#include <string>
#include <memory>
#include "new_rbt.hpp"

std::string * new_str (std::string &ref, std::allocator<std::string> alloc )
{
    std::string *ptr;
   
    ptr = alloc.allocate(1);
    alloc.construct(ptr, ref);
    return ptr;
}

int main()
{

    ft::pair<int, std::string> p1 = ft::make_pair<int, std::string>(1, "Siemanko");
    ft::pair<int, std::string> p2 = ft::make_pair<int, std::string>(2, "Marek");
    ft::pair<int, std::string> p3 = ft::make_pair<int, std::string> (-2, "Borys");

    ft::new_RBT<int, std::string> s;
    s.insert(p1);
    s.insert(p3);
    s.insert(p2);
    s.delete_val(p3);
    s.delete_val(p1);
    s.delete_val(p2);
    s.print_tree();
    
}