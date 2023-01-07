#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "map.hpp"

int main() {
    ft::map<int, int> s;

    // for(int i = 0; i < 50; i++)
    // {
        // s.insert(ft::make_pair<int,int>(1,33));
    // }
    // s.erase(1);

    s.insert(ft::make_pair<int,int>(1,33));
    s.insert(ft::make_pair<int,int>(2,33));
    s.insert(ft::make_pair<int,int>(3,33));
    s.insert(ft::make_pair<int,int>(6,33));
    s.insert(ft::make_pair<int,int>(-1,33));
    s.insert(ft::make_pair<int,int>(43,33));
    s.insert(ft::make_pair<int,int>(0,33));
    //0
    //6

    // std::cout << s.size() << std::endl;
    
}


// Brum 
// Brum 
// Brum 
// Brum 
// Brum 
// Brum 