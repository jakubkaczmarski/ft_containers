#include "testing.hpp"
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