#include <iostream>
#include <string>
#include <memory>

std::string * new_str (std::string &ref, std::allocator<std::string> alloc )
{
    std::string *ptr;
   
    ptr = alloc.allocate(1);
    alloc.construct(ptr, ref);
    return ptr;
}

int main()
{
    std::string b = "Siemanko";
    std::allocator<std::string> alloc;
    std::string *ptr = new_str(b, alloc);

    std::cout << *ptr << std::endl;
    alloc.deallocate(ptr, 1);
}