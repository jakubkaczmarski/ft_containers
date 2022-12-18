#include "tools.hpp"
#include "rbt_iter.hpp"
#include <memory>
#include <iostream>

#define BLACK false
#define RED true


namespace ft
{
    template <typename Key, typename Value,
        typename Alloc = std::allocator<ft::pair<const Key, Value> >, typename Compare = std::less<Key> >
    class RBT
    {

        public:
            struct node;
            
            typedef Key key_type;
            typedef Value value_type;
            typedef ft::pair<const Key, Value> pair_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef ptrdiff_t difference_type;
            typedef size_t size_type;
            typedef node* iter;
            typedef const node * const_iter;
            typedef Compare key_compare;

            template<typename T>
            struct node
            {
                pointer data;
                iter    left;
                iter    right;
                iter    parent;
                bool    color;
            };

            RBT()
            {
                nil_ = RBT(0);
                nil_->color = true;
                // nil->left;
            }

            // void insert(node *ptr, T * value)
            // {
                
            // }


            RBT(const key_compare &compare = key_compare(), const allocator_type &alloc = allocator_type())
            {

            }

        private:
            node *root_;
            size_type size_;
            key_compare comp_;
            allocator_type alloc_;
            std::allocator<node> node_alloc_;
            node *nil_;
    };
}
