/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testing.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:01:04 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/08 01:01:24 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTING_HPP
#define TESTING_HPP
#include "test_utils.cpp"
#include <sys/time.h>
typedef struct timeval	t_timeval;

template<typename T>
void compareVectors(std::vector<T> v, std::vector<T> v2);
int	gettime(t_timeval start);
#endif