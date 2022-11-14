/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:09:27 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/11/14 01:40:16 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
// #include "../additional.hpp"
#include "RedBlackTreeIterator.hpp"
// #include "main.cpp"
#include "red_black_tree.hpp"

namespace ft
{
    template <typename Key, typename T, typename Compare = std::less<Key>, typename allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        typedef Key key_type;
        typedef T mapped_type;
        typedef ft::pair<const Key, T> value_type ;
        typedef size_t size_type;
        typedef  std::ptrdiff_t difference_type;
        typedef Compare key_compare ;
        typedef allocator allocator_type ;
        typedef value_type& reference ;
        typedef const value_type& const_reference;
        typedef typename allocator::pointer pointer;
        typedef typename allocator::const_pointer const_pointer;
        // typedef typename ft::RedBlackTreeIterator<typename T>::iterator iterator
        // typedef typename const_iterator
        // typedef reverse_iterator 
        // typedef const_reverse_iterator
        
        public:
        
        private:
        RBT<ft::pair<const Key, T> > tree;
        allocator alloc_;
    };
}

#endif
//Root of the tree
// 