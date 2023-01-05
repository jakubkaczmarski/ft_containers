/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 16:37:50 by kmeixner          #+#    #+#             */
/*   Updated: 2023/01/05 19:03:13 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include "map.hpp"

#define STDMAP std::map<int, int>
#define FTMAP ft::map<int, int>

#include <sys/time.h>
typedef struct timeval	t_timeval;

template<typename T>
void compareVectorsDetails(std::vector<T> v, std::vector<T> v2)
{
	int i = v.size();
	int j = v2.size();
	std::cout << std::endl;

	if (i != j)
		std::cout << "\x1B[31m" << "SIZES ARE DIFFERENT" <<  "\033[0m";
	int n = std::min(i, j);
	for (i = 0; i < n; i++)
	{
		if (v[i] != v2[i])
			std::cout << "Index: " << i << " \x1B[31m" << v[i] << " : " << v2[i] <<  "\033[0m"<< std::endl;
	}
}
template<typename T>
void compareVectors(std::vector<T> v, std::vector<T> v2)
{
	if (v == v2)
		std::cout << "\x1B[32m" << "OK" <<  "\033[0m";
	else
	{
		std::cout << "\x1B[31m" << "KO" <<  "\033[0m";
		compareVectorsDetails<T>(v, v2);
	}
}

int	gettime(t_timeval start)
{
	t_timeval	tv;
	int			tdiff;

	gettimeofday(&tv, NULL);
	tdiff = (tv.tv_sec - start.tv_sec) * 1000;
	tdiff += (tv.tv_usec - start.tv_usec) / 1000;
	return (tdiff);
}


template<typename map>
void pushtoVector(map *mp, std::vector<int> *v)
{
	v->push_back(mp->size());
	for (typename map::iterator it = mp->begin(); it != mp->end(); it++)
	{
		v->push_back(it->first);
		v->push_back(it->second);
	}
	v->push_back(mp->size());
}

int main()
{

    ft::map<int, int> kurwa;
    kurwa.insert(ft::make_pair<int, int>(12, 33));
	
}