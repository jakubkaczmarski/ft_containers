/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:17:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/09/07 17:16:06 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <memory>
//default (1)	
// explicit vector (const allocator_type& alloc = allocator_type());
// fill (2)	
// explicit vector (size_type n, const value_type& val = value_type(),
//                  const allocator_type& alloc = allocator_type());
// range (3)	
// template <class InputIterator>
//          vector (InputIterator first, InputIterator last,
//                  const allocator_type& alloc = allocator_type());
// copy (4)	
// vector (const vector& x);

template<typename T>
class Vector
{
    public:
    Vector(){
        std::allocator<T> alloc;
        arr_ = alloc.allocate(2);
        beg_ = arr_;
        l_el_ = arr_;
        alloc.construct( l_el_, 0);
        l_el_++;
        end_ = arr_ + 2;
    };
    
    Vector(size_t n, const T &val)
    {
        std::allocator<T> alloc;
        arr_ = alloc.allocate(n * 2);
        beg_ = arr_;
        l_el_ = arr_;
        for(int i  = 0; i < n; i++)
        {
            alloc.construct( l_el_, val);
            l_el_++;
        }
        end_ = beg_ + n * 2;
    }
    Vector (const Vector& x)
    {
        // beg_ = vector.
    }

    void    push_back(const T &val)
    {
        
    }
    
    T * get_arr()
    {
        return beg_;
    }
    private:
    T   *arr_;
    T    *beg_;
    T     *l_el_;
    T      *end_;
};


// #include "Vector.hpp"
#include <vector>
#include <iostream>
// #include <Vector.hpp>
int main()
{
    Vector<int> vecs(20, 3);
    int *arr = vecs.get_arr();
    for(int i = 0; i < 20; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    // std::vector<int>vec1(2);
    // vector<int> vec;/
}