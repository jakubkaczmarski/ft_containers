/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:17:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/09/07 19:20:44 by jkaczmar         ###   ########.fr       */
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

#include <iostream>
template<typename T>
class Vector
{
    public:
    Vector(){
        std::allocator<T> alloc;
        arr_ = alloc.allocate(2);
        beg_ = arr_;
        l_el_ = arr_;
        // l_el_++;
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
        std::allocator<T> alloc;
        if(l_el_ + 1  == end_)
        {
            T *tmp;
            T *beg_tmp;
            T *end_tmp;
            T   *tmp_l_el;
            //We are in need to realocate
            tmp = alloc.allocate(this->size() + 1 * 2);
            beg_tmp = tmp;
            tmp_l_el = beg_tmp;
            end_tmp = beg_tmp + (this->size() + 1 * 2);
            for( ; beg_ != l_el_ ; )
            {
                alloc.construct(tmp_l_el , *beg_);
                beg_++;
                tmp_l_el++;
            }
            alloc.construct(tmp_l_el, val);
            tmp_l_el++;
            alloc.deallocate(arr_, this->size());
            arr_ = tmp;
            beg_ = beg_tmp;
            end_ = end_tmp;
            l_el_ = tmp_l_el;
            // for(; beg_ != l_el_ ;)
            // {
            //     std::cout << *beg_ << std::endl;
            //     beg_++;
            // }
        }else{
    
            alloc.construct(l_el_, val);
            l_el_++;
        }
    }
    size_t  size()
    {
        return l_el_ - beg_;
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
// #include <Vector.hpp>
#include <vector>
int main()
{
    Vector<int> vecs;
    vecs.push_back(12);
    vecs.push_back(25);
    vecs.push_back(33);
    int *arr = vecs.get_arr();
    for(int i = 0; i < 3; i++)
    {
        std::cout << arr[i] << std::endl;
    }
    // std::vector<int>vec1(2);
    // vector<int> vec;/
}