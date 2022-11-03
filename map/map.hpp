#include <iostream>
#include "../additional.hpp"
namespace ft
{
    template<typename T, typename key_type>
    class map
    {
        template<typename T>
        struct Node
        {
            T   *data;
            key_type *key;
            Node *left;
            Node *right;
            Node *parent;

            bool color;  //  0 == black | 1 == red
        };
        std::pair<iterator, bool> insert( const value_type& value )
        {

        }
        private:

        Node<T> root;
    };
}


//Root of the tree
// 