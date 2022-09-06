/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:16:23 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/09/06 20:43:28 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>


//Allocate twice as much as you need with each reallocation
//What do we need in Vector :(((())))
//vec_ay allocated on the heap :))
//Pointer to the begining :()
//Pointer to the end :()
//Pointer to allocated memory :)
template<typename T>
class Vector
{
    public:
    Vector<T>();
    Vector<T>(size_t num_of_el){};
    void    push_back(const T &el)
    {
    };
    T   pop_back();
    size_t  capacity();
    size_t  size();
    private:
    T   *array_;
    T   *beg_;
    T   *end_;
    T   *cap_;
}
#endif