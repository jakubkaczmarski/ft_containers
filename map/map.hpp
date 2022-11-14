/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:09:27 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/11/14 02:03:30 by jkaczmar         ###   ########.fr       */
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
        // typedef typename ft::RedBlackTreeIterator<typename T>::iterator iterator;
        // typedef typename ft::const_RedBlackTreeIterator<typename T>::const_iterator const_iterator;
        // typedef reverse_iterator 
        // typedef const_reverse_iterator
    
        public:
        allocator_type get_allocator() const
        {
            return alloc_;
        }
        T &at(const Key &key)
        {
            
        }
        //return Reference to the requested value
        const T& at( const Key& key ) const
        {
            
        }
        T& operator[]( const Key& key )
        {

        }
        //Capacity
        bool empty() const
        {

        }
        
        size_type size() const
        {
            
        }
        
        size_type max_size() const
        {

        }
        //Modifiers
        void clear()
        {
            
        }
        // ft::pair<iterator, bool> insert( const value_type& value )
        // {
            
        // }
        // iterator insert( iterator pos, const value_type& value )
        // {
            
        // }
        template< class InputIt >
        void insert( InputIt first, InputIt last )
        {
            
        }

        // iterator erase( iterator pos )
        // {

        // }

        size_type erase( const Key& key )
        {
            
        }
        // iterator erase( iterator first, iterator last )
        // {

        // }
        void swap( map& other )
        {

        }
        //Lookup
        size_type count( const Key& key ) const
        {

        }

        // iterator find( const Key& key )
        // {
            
        // }

        // const_iterator find( const Key& key ) const
        // {
            
        // }
        
        // iterator find( const Key& key )
        // {
            
        // }

        // const_iterator find( const Key& key ) const
        // {
            
        // }
        
        // std::pair<iterator,iterator> equal_range( const Key& key )
        // {
            
        // }
        // std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
        // {
            
        // }

        // iterator lower_bound( const Key& key )
        // {
            
        // }

        // const_iterator lower_bound( const Key& key ) const
        // {
            
        // }
        
        // iterator upper_bound( const Key& key )
        // {

        // }
        
        // const_iterator upper_bound( const Key& key ) const
        // {
            
        // }
        

        //Observers
        key_compare key_comp() const
        {
            
        }
        // ft::map::value_compare value_comp() const
        // {
            
        // }
        private:
        RBT<ft::pair<const Key, T> > tree;
        allocator alloc_;
    };
}

#endif
//Root of the tree
// 