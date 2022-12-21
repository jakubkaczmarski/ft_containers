#include "vector.hpp"
#include <vector>
// #include "rbt_iter.hpp"
#include "rbt.hpp"
#include "tools.hpp"

int main()
{

    // ft::RBT<12, "s"> val;
    // ft::rbt<int, int> s;
    // ft::vector<int> vec;
    // std::vector<int> vec1;
    // vec.push_back(12);
    // vec.push_back(12321);
    // vec.push_back(12321);
    // vec1.push_back(12);
    // vec1.push_back(12321);
    // vec1.push_back(12321);
    // ft::vector<int>::iterator it = vec.begin();
    // vec1.insert(it1, 123);
    // std::vector<int>::iterator it1 = vec1.begin(); 
    // vec.insert(it, 123);
    // Node<int> s(12, BLACK);/
    // int b = 15;
    // insert(&s, b);
    ft::RBT<int, std::string> tree;
    ft::pair<int, std::string> s= ft::make_pair<int, std::string>(21, "Marek");
    ft::pair<int, std::string> s2= ft::make_pair<int, std::string>(1, "Borys");
    // ft::pair<int, std::string> s2= ft::make_pair<int, std::string>(5, "Borys");
    // int c = 31

    tree.insert(s2);
    tree.insert(s);
    tree.insert(s2);
    tree.insert(s2);
    tree.insert(s2);
    tree.insert(s2);
    tree.insert(s2);
    // tree.insert(s2);
    // tree.print_tree();
    tree.delete_(s);
    tree.delete_(s2);
    tree.delete_(s2);
    tree.delete_(s2);
    tree.delete_(s2);
    // tree.delete_(s2);
    // tree.delete_(s2);
    std::cout << "printing out the thingy" << std::endl;
    tree.print_tree();
    // tree.delete_(s2);
    // tree.print_tree();
    // tree.print_tree();
    // printf("\n");
    // std::cout << s.search(c) << std::endl;
    // s.delete_(b);
    // s.delete_(b);
    // s.delete_(b);
    // s.delete_(b);
    // s.delete_(b);
    // s.delete_(b);
    // s.print_tree();

    // int s = 12;
    // int b = 13;
    // ss.insert(s);
    // ss.insert(b);
    // ss.insert(s);
    
    // ft::rbt_iterator<node, ft::RBT<int, std::string> > s;
    // for(int i = 0; i < vec1.size(); i++)
    // {
        // std::cout << vec1[i] << std::endl;
    // }
}