/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_t.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 00:59:56 by jkaczmar          #+#    #+#             */
/*   Updated: 2023/01/08 01:01:43 by jkaczmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <set>
#include <vector>
#include "../set.hpp"
#include "testing.hpp"
#define STDSET std::set<int>
#define FTSET ft::set<int>

template<typename set>
void pushtoVector(set *mp, std::vector<int> *v)
{
	v->push_back(mp->size());
	for (typename set::iterator it = mp->begin(); it != mp->end(); it++)
	{
		v->push_back(*it);
	}
	v->push_back(mp->size());
}

int main()
{
	t_timeval start;
	int stdtime;
	int fttime;
	std::cout << "   _____ ______ _______ " << std::endl;
	std::cout << "  / ____|  ____|__   __|" << std::endl;
	std::cout << " | (___ | |__     | |   " << std::endl;
	std::cout << "  \\___ \\|  __|    | |   " << std::endl;
	std::cout << "  ____) | |____   | |   " << std::endl;
	std::cout << " |_____/|______|  |_|   " << std::endl;

	std::cout << "\nTesting set constructors:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0; i < 10000; i++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		STDSET std2(std1.begin(), std1.end());
		STDSET std3(std2);
		STDSET std4;
		stdtime = gettime(start);
		pushtoVector<STDSET >(&std2, &v1);
		pushtoVector<STDSET >(&std3, &v1);
		pushtoVector<STDSET >(&std4, &v1);


		FTSET ft1;
		for (int i = 0; i < 10000; i++)
			ft1.insert(i);
		gettimeofday(&start, NULL);
		FTSET ft2(ft1.begin(), ft1.end());
		FTSET ft3(ft2);
		FTSET ft4;
		fttime = gettime(start);
		pushtoVector<FTSET >(&ft2, &v2);
		pushtoVector<FTSET >(&ft3, &v2);
		pushtoVector<FTSET >(&ft4, &v2);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set assignment operator:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0; i < 10000; i++)
			std1.insert(i);
		STDSET std2;
		STDSET std3;
		STDSET std4;
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		pushtoVector<STDSET>(&std3, &v1);
		pushtoVector<STDSET>(&std4, &v1);
		gettimeofday(&start, NULL);
		std2 = std1;
		std4 = std3;
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		pushtoVector<STDSET>(&std3, &v1);
		pushtoVector<STDSET>(&std4, &v1);
		std1 = std4;
		pushtoVector<STDSET>(&std1, &v1);

		FTSET ft1;
		for (int i = 0; i < 10000; i++)
			ft1.insert(i);
		FTSET ft2;
		FTSET ft3;
		FTSET ft4;
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		pushtoVector<FTSET>(&ft3, &v2);
		pushtoVector<FTSET>(&ft4, &v2);
		gettimeofday(&start, NULL);
		ft2 = ft1;
		ft4 = ft3;
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		pushtoVector<FTSET>(&ft3, &v2);
		pushtoVector<FTSET>(&ft4, &v2);
		ft1 = ft4;
		pushtoVector<FTSET>(&ft1, &v2);
		
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting set iterators:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET::iterator stdit;
		STDSET::const_iterator stdcit;
		STDSET::reverse_iterator stdrev;
		STDSET::const_reverse_iterator stdcrev;
		for (int i = 0; i < 5; i++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		stdit = std1.begin();
		stdcit = std1.begin();
		stdrev = std1.rbegin();
		stdcrev = std1.rbegin();
		v1.push_back((stdit == stdcit));
		v1.push_back((stdrev == stdcrev));
		for (; stdit != std1.end(); stdit++)
		{
			v1.push_back(*stdit);
			v1.push_back(*stdit);
		}
		v1.push_back((stdit == std1.end()));
		--stdit;
		for (; stdit != std1.begin(); stdit--)
		{
			v1.push_back(*stdit);
			v1.push_back(*stdit);
		}
		for (; stdcit != std1.end(); stdcit++)
		{
			v1.push_back(*stdcit);
			v1.push_back(*stdcit);
		}
		v1.push_back((stdcit == std1.end()));
		--stdcit;
		for (; stdcit != std1.begin(); stdcit--)
		{
			v1.push_back(*stdcit);
			v1.push_back(*stdcit);
		}
		for (; stdrev != std1.rend(); stdrev++)
		{
			v1.push_back(*stdrev);
			v1.push_back(*stdrev);
		}
		v1.push_back((stdrev == std1.rend()));
		--stdrev;
		for (; stdrev != std1.rbegin(); stdrev--)
		{
			v1.push_back(*stdrev);
			v1.push_back(*stdrev);
		}
		for (; stdcrev != std1.rend(); stdcrev++)
		{
			v1.push_back(*stdcrev);
			v1.push_back(*stdcrev);
		}
		v1.push_back((stdcrev == std1.rend()));
		--stdcrev;
		for (; stdcrev != std1.rbegin(); stdcrev--)
		{
			v1.push_back(*stdcrev);
			v1.push_back(*stdcrev);
		}
		stdtime = gettime(start);



		FTSET ft1;
		FTSET::iterator ftit;
		FTSET::const_iterator ftcit;
		FTSET::reverse_iterator ftrev;
		FTSET::const_reverse_iterator ftcrev;
		for (int i = 0; i < 5; i++)
			ft1.insert(i);
		gettimeofday(&start, NULL);
		ftit = ft1.begin();
		ftcit = ft1.begin();
		ftrev = ft1.rbegin();
		ftcrev = ft1.rbegin();
		v2.push_back((ftit == ftcit));
		v2.push_back((ftrev == ftcrev));
		for (; ftit != ft1.end(); ftit++)
		{
			v2.push_back(*ftit);
			v2.push_back(*ftit);
		}
		v2.push_back((ftit == ft1.end()));
		--ftit;
		for (; ftit != ft1.begin(); ftit--)
		{
			v2.push_back(*ftit);
			v2.push_back(*ftit);
		}
		for (; ftcit != ft1.end(); ftcit++)
		{
			v2.push_back(*ftcit);
			v2.push_back(*ftcit);
		}
		v2.push_back((ftcit == ft1.end()));
		--ftcit;
		for (; ftcit != ft1.begin(); ftcit--)
		{
			v2.push_back(*ftcit);
			v2.push_back(*ftcit);
		}
		for (; ftrev != ft1.rend(); ftrev++)
		{
			v2.push_back(*ftrev);
			v2.push_back(*ftrev);
		}
		v2.push_back((ftrev == ft1.rend()));
		--ftrev;
		for (; ftrev != ft1.rbegin(); ftrev--)
		{
			v2.push_back(*ftrev);
			v2.push_back(*ftrev);
		}
		for (; ftcrev != ft1.rend(); ftcrev++)
		{
			v2.push_back(*ftcrev);
			v2.push_back(*ftcrev);
		}
		v2.push_back((ftcrev == ft1.rend()));
		--ftcrev;
		for (; ftcrev != ft1.rbegin(); ftcrev--)
		{
			v2.push_back(*ftcrev);
			v2.push_back(*ftcrev);
		}
		fttime = gettime(start);



		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set empty, size:" << std::endl;
	{
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		for (int i = 0; i < 10000; i++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		v1.push_back(std1.empty());
		v1.push_back(std1.size());
		v1.push_back(std2.empty());
		v1.push_back(std2.size());
		stdtime = gettime(start);


		FTSET ft1;
		FTSET ft2;
		for (int i = 0; i < 10000; i++)
			ft1.insert(i);
		gettimeofday(&start, NULL);
		v2.push_back(ft1.empty());
		v2.push_back(ft1.size());
		v2.push_back(ft2.empty());
		v2.push_back(ft2.size());
		fttime = gettime(start);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting map clear:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		for (int i = 0; i < 100000; i++)
			std1.insert(i);
		pushtoVector(&std1, &v1);
		pushtoVector(&std2, &v1);
		gettimeofday(&start, NULL);
		std1.clear();
		std2.clear();
		stdtime = gettime(start);
		pushtoVector(&std1, &v1);
		pushtoVector(&std2, &v1);


		FTSET ft1;
		FTSET ft2;
		for (int i = 0; i < 100000; i++)
			ft1.insert(i);
		pushtoVector(&ft1, &v2);
		pushtoVector(&ft2, &v2);
		gettimeofday(&start, NULL);
		ft1.clear();
		ft2.clear();
		fttime = gettime(start);
		pushtoVector(&ft1, &v2);
		pushtoVector(&ft2, &v2);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set single insert:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		std::pair<STDSET::iterator, bool> stdpair;
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			stdpair = std1.insert(i);
			v1.push_back(*stdpair.first);
			v1.push_back(stdpair.second);
			stdpair = std2.insert(2500000 - i);	
			v1.push_back(*stdpair.first);
			v1.push_back(stdpair.second);
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			stdpair = std1.insert(i);
			v1.push_back(*stdpair.first);
			v1.push_back(stdpair.second);
			stdpair = std2.insert(2500000 - i);	
			v1.push_back(*stdpair.first);
			v1.push_back(stdpair.second);
		}
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);

		FTSET ft1;
		FTSET ft2;
		ft::pair<FTSET::iterator, bool> ftpair;
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ftpair = ft1.insert(i);
			v2.push_back(*ftpair.first);
			v2.push_back(ftpair.second);
			ftpair = ft2.insert(2500000 - i);	
			v2.push_back(*ftpair.first);
			v2.push_back(ftpair.second);
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			ftpair = ft1.insert(i);
			v2.push_back(*ftpair.first);
			v2.push_back(ftpair.second);
			ftpair = ft2.insert(2500000 - i);	
			v2.push_back(*ftpair.first);
			v2.push_back(ftpair.second);
		}
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set single insert with hint:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			std1.insert(std1.begin(), i);
			std2.insert(std2.begin(), 2500000 - i);	
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			std1.insert(std1.begin(), i);
			std2.insert(std2.begin(), 2500000 - i);	
		}
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);

		FTSET ft1;
		FTSET ft2;
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ft1.insert(ft1.begin(), i);
			ft2.insert(ft2.begin(), 2500000 - i);	
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			ft1.insert(ft1.begin(), i);
			ft2.insert(ft2.begin(), 2500000 - i);	
		}
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting set range insert:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		std2.insert(std1.begin(), std1.end());
		std2.insert(std1.begin(), std1.end());
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		

		FTSET ft1;
		FTSET ft2;
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(i);
		gettimeofday(&start, NULL);

		ft2.insert(ft1.begin(), ft1.end());
		ft2.insert(ft1.begin(), ft1.end());
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set iterator erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		pushtoVector<STDSET>(&std1, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		while (std1.begin() != std1.end())
			std1.erase(std1.begin());
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		

		FTSET ft1;
		pushtoVector<FTSET>(&ft1, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(i);
		
		gettimeofday(&start, NULL);
		while (ft1.begin() != ft1.end())
			ft1.erase(ft1.begin());
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set key value erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		pushtoVector<STDSET>(&std1, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		for (int i = 25; i < 49920; i++)
			v1.push_back(std1.erase(i));
		for (int i = 25; i < 49920; i++)
			v1.push_back(std1.erase(i));
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		

		FTSET ft1;
		pushtoVector<FTSET>(&ft1, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(i);
		
		gettimeofday(&start, NULL);
		for (int i = 25; i < 49920; i++)
			v2.push_back(ft1.erase(i));
		for (int i = 25; i < 49920; i++)
			v2.push_back(ft1.erase(i));
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting set range erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			std1.insert(i);
			std2.insert(i);
		}
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		STDSET::iterator stdit = std2.begin();
		for (int i = 0; i < 2000; i++)
			stdit++;
		gettimeofday(&start, NULL);
		std1.erase(std1.begin(), std1.end());
		std2.erase(stdit, std2.end());
		stdtime = gettime(start);
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		
		
		FTSET ft1;
		FTSET ft2;
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ft1.insert(i);
			ft2.insert(i);
		}
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		FTSET::iterator ftit = ft2.begin();
		for (int i = 0; i < 2000; i++)
			ftit++;
		gettimeofday(&start, NULL);
		ft1.erase(ft1.begin(), ft1.end());
		ft2.erase(ftit, ft2.end());
		fttime = gettime(start);
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting set swap:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;
		for (int i = 0, j = 5; i < 5; i++, j++)
		{
			std1.insert(i);
			std2.insert(j);
		}
		
		STDSET::iterator stdit1 = std1.begin();
		STDSET::iterator stdit2 = std2.begin();
		v1.push_back(stdit1 == std1.begin());
		v1.push_back(stdit2 == std2.begin());
		v1.push_back(stdit1 == std2.begin());
		v1.push_back(stdit2 == std1.begin());
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		
		gettimeofday(&start, NULL);
		std1.swap(std2);
		stdtime = gettime(start);

		v1.push_back(stdit1 == std1.begin());
		v1.push_back(stdit2 == std2.begin());
		v1.push_back(stdit1 == std2.begin());
		v1.push_back(stdit2 == std1.begin());
		pushtoVector<STDSET>(&std1, &v1);
		pushtoVector<STDSET>(&std2, &v1);
		

		FTSET ft1;
		FTSET ft2;
		for (int i = 0, j = 5; i < 5; i++, j++)
		{
			ft1.insert(i);
			ft2.insert(j);
		}
		FTSET::iterator ftit1 = ft1.begin();
		FTSET::iterator ftit2 = ft2.begin();
		v2.push_back(ftit1 == ft1.begin());
		v2.push_back(ftit2 == ft2.begin());
		v2.push_back(ftit1 == ft2.begin());
		v2.push_back(ftit2 == ft1.begin());
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);
		
		gettimeofday(&start, NULL);
		ft1.swap(ft2);
		fttime = gettime(start);
		
		v2.push_back(ftit1 == ft1.begin());
		v2.push_back(ftit2 == ft2.begin());
		v2.push_back(ftit1 == ft2.begin());
		v2.push_back(ftit2 == ft1.begin());
		pushtoVector<FTSET>(&ft1, &v2);
		pushtoVector<FTSET>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting set count, find:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(i);
		gettimeofday(&start, NULL);
		for (int i = -3; i < 8; i++)
			v1.push_back(std1.count(i));
		v1.push_back(*std1.find(3));
		v1.push_back(*std1.find(1));
		v1.push_back(*std1.find(0));
		v1.push_back((std1.find(4) == std1.end()));
		v1.push_back((std1.find(12) == std1.end()));
		stdtime = gettime(start);
		

		FTSET ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(i);
		gettimeofday(&start, NULL);
		for (int i = -3; i < 8; i++)
			v2.push_back(ft1.count(i));
		v2.push_back(*ft1.find(3));
		v2.push_back(*ft1.find(1));
		v2.push_back(*ft1.find(0));
		v2.push_back((ft1.find(4) == ft1.end()));
		v2.push_back((ft1.find(12) == ft1.end()));
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map equal range:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(i);
		std1.insert(12);
		gettimeofday(&start, NULL);
		v1.push_back(*std1.equal_range(2).first);
		v1.push_back(*std1.equal_range(2).first);
		v1.push_back(*std1.equal_range(2).second);
		v1.push_back(*std1.equal_range(2).second);
		v1.push_back(*std1.equal_range(4).first);
		v1.push_back(*std1.equal_range(4).first);
		v1.push_back(*std1.equal_range(4).second);
		v1.push_back(*std1.equal_range(4).second);
		v1.push_back(*std1.equal_range(8).first);
		v1.push_back(*std1.equal_range(8).first);
		v1.push_back(*std1.equal_range(8).second);
		v1.push_back(*std1.equal_range(8).second);
		v1.push_back(std1.equal_range(1234).first == std1.end());
		v1.push_back(std1.equal_range(1234).second == std1.end());
		stdtime = gettime(start);
		

		FTSET ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(i);
		ft1.insert(12);
		gettimeofday(&start, NULL);
		v2.push_back(*ft1.equal_range(2).first);
		v2.push_back(*ft1.equal_range(2).first);
		v2.push_back(*ft1.equal_range(2).second);
		v2.push_back(*ft1.equal_range(2).second);
		v2.push_back(*ft1.equal_range(4).first);
		v2.push_back(*ft1.equal_range(4).first);
		v2.push_back(*ft1.equal_range(4).second);
		v2.push_back(*ft1.equal_range(4).second);
		v2.push_back(*ft1.equal_range(8).first);
		v2.push_back(*ft1.equal_range(8).first);
		v2.push_back(*ft1.equal_range(8).second);
		v2.push_back(*ft1.equal_range(8).second);
		v2.push_back(ft1.equal_range(1234).first == ft1.end());
		v2.push_back(ft1.equal_range(1234).second == ft1.end());
		
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting map lower bound:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(i);
		std1.insert(12);
		gettimeofday(&start, NULL);
		v1.push_back(*std1.lower_bound(2));
		v1.push_back(*std1.lower_bound(2));
		v1.push_back(*std1.lower_bound(2));
		v1.push_back(*std1.lower_bound(2));
		v1.push_back(*std1.lower_bound(4));
		v1.push_back(*std1.lower_bound(4));
		v1.push_back(*std1.lower_bound(4));
		v1.push_back(*std1.lower_bound(4));
		v1.push_back(*std1.lower_bound(8));
		v1.push_back(*std1.lower_bound(8));
		v1.push_back(*std1.lower_bound(8));
		v1.push_back(*std1.lower_bound(8));
		v1.push_back(std1.lower_bound(1234) == std1.end());
		v1.push_back(std1.lower_bound(1234) == std1.end());
		stdtime = gettime(start);
		

		FTSET ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(i);
		ft1.insert(12);
		gettimeofday(&start, NULL);
		v2.push_back(*ft1.lower_bound(2));
		v2.push_back(*ft1.lower_bound(2));
		v2.push_back(*ft1.lower_bound(2));
		v2.push_back(*ft1.lower_bound(2));
		v2.push_back(*ft1.lower_bound(4));
		v2.push_back(*ft1.lower_bound(4));
		v2.push_back(*ft1.lower_bound(4));
		v2.push_back(*ft1.lower_bound(4));
		v2.push_back(*ft1.lower_bound(8));
		v2.push_back(*ft1.lower_bound(8));
		v2.push_back(*ft1.lower_bound(8));
		v2.push_back(*ft1.lower_bound(8));
		v2.push_back(ft1.lower_bound(1234) == ft1.end());
		v2.push_back(ft1.lower_bound(1234) == ft1.end());
		
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map upper bound:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(i);
		std1.insert(12);
		gettimeofday(&start, NULL);
		v1.push_back(*std1.upper_bound(2));
		v1.push_back(*std1.upper_bound(2));
		v1.push_back(*std1.upper_bound(2));
		v1.push_back(*std1.upper_bound(2));
		v1.push_back(*std1.upper_bound(4));
		v1.push_back(*std1.upper_bound(4));
		v1.push_back(*std1.upper_bound(4));
		v1.push_back(*std1.upper_bound(4));
		v1.push_back(*std1.upper_bound(8));
		v1.push_back(*std1.upper_bound(8));
		v1.push_back(*std1.upper_bound(8));
		v1.push_back(*std1.upper_bound(8));
		v1.push_back(std1.upper_bound(1234) == std1.end());
		v1.push_back(std1.upper_bound(1234) == std1.end());
		stdtime = gettime(start);
		

		FTSET ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(i);
		ft1.insert(12);
		gettimeofday(&start, NULL);
		v2.push_back(*ft1.upper_bound(2));
		v2.push_back(*ft1.upper_bound(2));
		v2.push_back(*ft1.upper_bound(2));
		v2.push_back(*ft1.upper_bound(2));
		v2.push_back(*ft1.upper_bound(4));
		v2.push_back(*ft1.upper_bound(4));
		v2.push_back(*ft1.upper_bound(4));
		v2.push_back(*ft1.upper_bound(4));
		v2.push_back(*ft1.upper_bound(8));
		v2.push_back(*ft1.upper_bound(8));
		v2.push_back(*ft1.upper_bound(8));
		v2.push_back(*ft1.upper_bound(8));
		v2.push_back(ft1.upper_bound(1234) == ft1.end());
		v2.push_back(ft1.upper_bound(1234) == ft1.end());
		
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map relational operators:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDSET std1;
		STDSET std2;

		gettimeofday(&start, NULL);
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std1.insert(1);
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std2.insert(3);
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std2.insert(1);
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std1.insert(3);
		stdtime = gettime(start);
		

		FTSET ft1;
		FTSET ft2;

		gettimeofday(&start, NULL);
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft1.insert(1);
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft2.insert(3);
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft2.insert(1);
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft1.insert(3);
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
}