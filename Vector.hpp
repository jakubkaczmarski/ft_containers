/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:16:23 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/08/25 20:44:58 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T>
class vector
{
    public:
    vector<T>(){
        arr = new T[1];
        current = 0;
        capacity = 1;
    }
    vector<T>(T val){
        capacity = val * 2;
        arr = new T[capacity];
        current = val;
    };
    ~vector<T>()
    {
        delete [] arr;
    }
    private:
    T *arr;
    int current;
    int  capacity;
};

#endif