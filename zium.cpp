#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "map.hpp"

int main() {
    ft::map<int, int> s;
    for(int i = 0; i < 50; i++)
    {
        s.insert(ft::make_pair<int,int>(i,33));
    }
    s.erase(1);
    std::cout << s.size() << std::endl;
    
}