/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 00:09:27 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/11/14 01:23:05 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
// #include "../additional.hpp"
// #include "main.cpp"
#include "red_black_tree.hpp"

namespace ft
{
    template <typename Key, typename T, typename Comapre = std::less<Key>, typename allocator = std::allocator<ft::pair<const Key, T> > >
    class map
    {
        
        private:
        RBT<ft::pair<const Key, T> > tree;
    };
}

#endif
//Root of the tree
// 