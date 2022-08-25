/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:16:23 by jkaczmar          #+#    #+#             */
/*   Updated: 2022/08/25 13:22:51 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

template<typename T>
class vector
{
    public:
    void vector(){};

    private:
    T *arr;
    T *beg;
    T *end;
    T  *capacity_ptr;
};

#endif