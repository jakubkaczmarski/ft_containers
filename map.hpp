/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 18:23:29 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/03 23:45:55 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "new_rbt.hpp"
#include "rbt_iter.hpp"
#include "tools.hpp"
// #include <functional>
#include <memory>

namespace ft
{
    template<typename Key, typename T, 
        typename Compare = std::less<Key>, typename allocator_type = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        public:
        typedef Key key_type;
        typedef T mapped_type;
        typedef pair<const key_type, mapped_type> value_type;
        typedef Compare key_compare;
        typedef typename allocator_type::reference reference;
        typedef typename allocator_type::const_reference const_reference;
        typedef typename allocator_type::pointer pointer;
        typedef typename allocator_type::const_pointer const_pointer;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
    

        private:
        typedef ft::new_RBT<key_type, mapped_type, allocator_type, key_compare> tree_type;

        public:
        
        typedef rbt_iterator<tree_type, typename tree_type::node> iterator;
        typedef const_rbt_iterator<typename tree_type::node, tree_type> const_iterator;
        typedef ft::reverse_iterator<iterator> reverse_iterator;
        typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

        class value_compare : std::binary_function<value_type, value_type, bool>
        {
            friend class map;

            protected:
                Compare comp;
                value_compare (Compare c) : comp(c) {} 
            
            public:
                typedef bool result_type;
                typedef value_type first_arg_type;
                typedef value_type second_arg_type;
                bool operator() (const value_type &x, const value_type &y) const
                {
                    return comp(x.first, x.second);    
                }
        };
        explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
        : tree_(), comp_(comp), alloc_(alloc)
        {
                
        }        
        // ft::pair<iterator,bool> insert (const value_type& val)
        // {
        //     tree_.insert(val);
		//     // iterator temp = iterator(this->_tree.insert(val), this->_tree.getEnd(), this->_tree.getRend());
		//     // return (ft::make_pair<iterator, bool>(temp, booltemp));
        // }
            
            private:
            tree_type tree_;
            key_compare comp_;
            allocator_type alloc_;
        };
};