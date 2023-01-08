
#include <map>
#include <vector>
#include "../map.hpp"
#include "testing.hpp"
#define STDMAP std::map<int, int>
#define FTMAP ft::map<int, int>

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
	t_timeval start;
	int stdtime;
	int fttime;
	std::cout << "  __  __          _____  " << std::endl;
	std::cout << " |  \\/  |   /\\   |  __ \\ " << std::endl;
	std::cout << " | \\  / |  /  \\  | |__)|" << std::endl;
	std::cout << " | |\\/| | / /\\ \\ |  ___/ " << std::endl;
	std::cout << " | |  | |/ ____ \\| |     " << std::endl;
	std::cout << " |_|  |_/_/    \\_\\_|     " << std::endl;

	std::cout << "\nTesting map constructors:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		STDMAP std2(std1.begin(), std1.end());
		STDMAP std3(std2);
		STDMAP std4;
		stdtime = gettime(start);
		pushtoVector<STDMAP >(&std2, &v1);
		pushtoVector<STDMAP >(&std3, &v1);
		pushtoVector<STDMAP >(&std4, &v1);


		FTMAP ft1;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		gettimeofday(&start, NULL);
		FTMAP ft2(ft1.begin(), ft1.end());
		FTMAP ft3(ft2);
		FTMAP ft4;
		fttime = gettime(start);
		pushtoVector<FTMAP >(&ft2, &v2);
		pushtoVector<FTMAP >(&ft3, &v2);
		pushtoVector<FTMAP >(&ft4, &v2);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map assignment operator:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			std1.insert(std::make_pair(i, j));
		STDMAP std2;
		STDMAP std3;
		STDMAP std4;
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		pushtoVector<STDMAP>(&std3, &v1);
		pushtoVector<STDMAP>(&std4, &v1);
		gettimeofday(&start, NULL);
		std2 = std1;
		std4 = std3;
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		pushtoVector<STDMAP>(&std3, &v1);
		pushtoVector<STDMAP>(&std4, &v1);
		std1 = std4;
		pushtoVector<STDMAP>(&std1, &v1);

		FTMAP ft1;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		FTMAP ft2;
		FTMAP ft3;
		FTMAP ft4;
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		pushtoVector<FTMAP>(&ft3, &v2);
		pushtoVector<FTMAP>(&ft4, &v2);
		gettimeofday(&start, NULL);
		ft2 = ft1;
		ft4 = ft3;
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		pushtoVector<FTMAP>(&ft3, &v2);
		pushtoVector<FTMAP>(&ft4, &v2);
		ft1 = ft4;
		pushtoVector<FTMAP>(&ft1, &v2);
		
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

std::cout << "\nTesting map at and []:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		for (int i = 0, j = 5; i < 12; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		v1.push_back(std1.at(5));
		v1.push_back(std1.at(0));
		v1.push_back(std1.at(2));
		v1.push_back(std1.at(11));
		v1.push_back(std1.at(7));
		try
		{
			int j = std1.at(15);
			v1.push_back(j);
		}
		catch (const std::out_of_range &oor)
		{
			v1.push_back(-1);
		}
		v1.push_back(std1.size());
		v1.push_back(std1[0]);
		v1.push_back(std1[5]);
		v1.push_back(std1[7]);
		v1.push_back(std1[15]);
		v1.push_back(std1.at(15));
		v1.push_back(std1.size());
		stdtime = gettime(start);



		ft::map<int, int> ft1;
		for (int i = 0, j = 5; i < 12; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		gettimeofday(&start, NULL);
		v2.push_back(ft1.at(5));
		v2.push_back(ft1.at(0));
		v2.push_back(ft1.at(2));
		v2.push_back(ft1.at(11));
		v2.push_back(ft1.at(7));
		try
		{
			int j = ft1.at(15);
			v2.push_back(j);
		}
		catch (const std::out_of_range &oor)
		{
			v2.push_back(-1);
		}
		v2.push_back(ft1.size());
		v2.push_back(ft1[0]);
		v2.push_back(ft1[5]);
		v2.push_back(ft1[7]);
		v2.push_back(ft1[15]);
		v2.push_back(ft1.at(15));
		v2.push_back(ft1.size());
		fttime = gettime(start);



		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}


	std::cout << "\nTesting map iterators:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP::iterator stdit;
		STDMAP::const_iterator stdcit;
		STDMAP::reverse_iterator stdrev;
		STDMAP::const_reverse_iterator stdcrev;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		stdit = std1.begin();
		stdcit = std1.begin();
		stdrev = std1.rbegin();
		stdcrev = std1.rbegin();
		v1.push_back((stdit == stdcit));
		v1.push_back((stdrev == stdcrev));
		for (; stdit != std1.end(); stdit++)
		{
			v1.push_back(stdit->first);
			v1.push_back(stdit->second);
		}
		v1.push_back((stdit == std1.end()));
		--stdit;
		for (; stdit != std1.begin(); stdit--)
		{
			v1.push_back(stdit->first);
			v1.push_back(stdit->second);
		}
		for (; stdcit != std1.end(); stdcit++)
		{
			v1.push_back(stdcit->first);
			v1.push_back(stdcit->second);
		}
		v1.push_back((stdcit == std1.end()));
		--stdcit;
		for (; stdcit != std1.begin(); stdcit--)
		{
			v1.push_back(stdcit->first);
			v1.push_back(stdcit->second);
		}
		for (; stdrev != std1.rend(); stdrev++)
		{
			v1.push_back(stdrev->first);
			v1.push_back(stdrev->second);
		}
		v1.push_back((stdrev == std1.rend()));
		--stdrev;
		for (; stdrev != std1.rbegin(); stdrev--)
		{
			v1.push_back(stdrev->first);
			v1.push_back(stdrev->second);
		}
		for (; stdcrev != std1.rend(); stdcrev++)
		{
			v1.push_back(stdcrev->first);
			v1.push_back(stdcrev->second);
		}
		v1.push_back((stdcrev == std1.rend()));
		--stdcrev;
		for (; stdcrev != std1.rbegin(); stdcrev--)
		{
			v1.push_back(stdcrev->first);
			v1.push_back(stdcrev->second);
		}
		stdtime = gettime(start);



		FTMAP ft1;
		FTMAP::iterator ftit;
		FTMAP::const_iterator ftcit;
		FTMAP::reverse_iterator ftrev;
		FTMAP::const_reverse_iterator ftcrev;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		gettimeofday(&start, NULL);
		ftit = ft1.begin();
		ftcit = ft1.begin();
		ftrev = ft1.rbegin();
		ftcrev = ft1.rbegin();
		v2.push_back((ftit == ftcit));
		v2.push_back((ftrev == ftcrev));
		for (; ftit != ft1.end(); ftit++)
		{
			v2.push_back(ftit->first);
			v2.push_back(ftit->second);
		}
		v2.push_back((ftit == ft1.end()));
		--ftit;
		for (; ftit != ft1.begin(); ftit--)
		{
			v2.push_back(ftit->first);
			v2.push_back(ftit->second);
		}
		for (; ftcit != ft1.end(); ftcit++)
		{
			v2.push_back(ftcit->first);
			v2.push_back(ftcit->second);
		}
		v2.push_back((ftcit == ft1.end()));
		--ftcit;
		for (; ftcit != ft1.begin(); ftcit--)
		{
			v2.push_back(ftcit->first);
			v2.push_back(ftcit->second);
		}
		for (; ftrev != ft1.rend(); ftrev++)
		{
			v2.push_back(ftrev->first);
			v2.push_back(ftrev->second);
		}
		v2.push_back((ftrev == ft1.rend()));
		--ftrev;
		for (; ftrev != ft1.rbegin(); ftrev--)
		{
			v2.push_back(ftrev->first);
			v2.push_back(ftrev->second);
		}
		for (; ftcrev != ft1.rend(); ftcrev++)
		{
			v2.push_back(ftcrev->first);
			v2.push_back(ftcrev->second);
		}
		v2.push_back((ftcrev == ft1.rend()));
		--ftcrev;
		for (; ftcrev != ft1.rbegin(); ftcrev--)
		{
			v2.push_back(ftcrev->first);
			v2.push_back(ftcrev->second);
		}
		fttime = gettime(start);



		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map empty, size:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		v1.push_back(std1.empty());
		v1.push_back(std1.size());
		v1.push_back(std2.empty());
		v1.push_back(std2.size());
		stdtime = gettime(start);


		FTMAP ft1;
		FTMAP ft2;
		for (int i = 0, j = 5; i < 10000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
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

		STDMAP std1;
		STDMAP std2;
		for (int i = 0, j = 5; i < 100000; i++, j++)
			std1.insert(std::make_pair(i, j));
		pushtoVector(&std1, &v1);
		pushtoVector(&std2, &v1);
		gettimeofday(&start, NULL);
		std1.clear();
		std2.clear();
		stdtime = gettime(start);
		pushtoVector(&std1, &v1);
		pushtoVector(&std2, &v1);


		FTMAP ft1;
		FTMAP ft2;
		for (int i = 0, j = 5; i < 100000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
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
	std::cout << "\nTesting map single insert:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		std::pair<STDMAP::iterator, bool> stdpair;
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			stdpair = std1.insert(std::make_pair(i, j));
			v1.push_back(stdpair.first->first);
			v1.push_back(stdpair.first->second);
			v1.push_back(stdpair.second);
			stdpair = std2.insert(std::make_pair(2500000 - i, 2500000 - j));	
			v1.push_back(stdpair.first->first);
			v1.push_back(stdpair.first->second);
			v1.push_back(stdpair.second);
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			stdpair = std1.insert(std::make_pair(i, j));
			v1.push_back(stdpair.first->first);
			v1.push_back(stdpair.first->second);
			v1.push_back(stdpair.second);
			stdpair = std2.insert(std::make_pair(2500000 - i, 2500000 - j));	
			v1.push_back(stdpair.first->first);
			v1.push_back(stdpair.first->second);
			v1.push_back(stdpair.second);
		}
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);

		FTMAP ft1;
		FTMAP ft2;
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		ft::pair<FTMAP::iterator, bool> ftpair;
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ftpair = ft1.insert(ft::make_pair(i, j));
			v2.push_back(ftpair.first->first);
			v2.push_back(ftpair.first->second);
			v2.push_back(ftpair.second);
			ftpair = ft2.insert(ft::make_pair(2500000 - i, 2500000 - j));	
			v2.push_back(ftpair.first->first);
			v2.push_back(ftpair.first->second);
			v2.push_back(ftpair.second);
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			ftpair = ft1.insert(ft::make_pair(i, j));
			v2.push_back(ftpair.first->first);
			v2.push_back(ftpair.first->second);
			v2.push_back(ftpair.second);
			ftpair = ft2.insert(ft::make_pair(2500000 - i, 2500000 - j));	
			v2.push_back(ftpair.first->first);
			v2.push_back(ftpair.first->second);
			v2.push_back(ftpair.second);
		}
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map single insert with hint:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			std1.insert(std1.begin(), std::make_pair(i, j));
			std2.insert(std2.begin(), std::make_pair(2500000 - i, 2500000 - j));	
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			std1.insert(std1.begin(), std::make_pair(i, j));
			std2.insert(std2.begin(), std::make_pair(2500000 - i, 2500000 - j));	
		}
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);

		FTMAP ft1;
		FTMAP ft2;
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		gettimeofday(&start, NULL);
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ft1.insert(ft1.begin(), ft::make_pair(i, j));
			ft2.insert(ft2.begin(), ft::make_pair(2500000 - i, 2500000 - j));	
		}
		for (int i = 25, j = 5; i < 500; i++, j++)
		{
			ft1.insert(ft1.begin(), ft::make_pair(i, j));
			ft2.insert(ft2.begin(), ft::make_pair(2500000 - i, 2500000 - j));	
		}
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}


	std::cout << "\nTesting map range insert:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		std2.insert(std1.begin(), std1.end());
		std2.insert(std1.begin(), std1.end());
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		

		FTMAP ft1;
		FTMAP ft2;
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		gettimeofday(&start, NULL);

		ft2.insert(ft1.begin(), ft1.end());
		ft2.insert(ft1.begin(), ft1.end());
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map iterator erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		pushtoVector<STDMAP>(&std1, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		while (std1.begin() != std1.end())
			std1.erase(std1.begin());
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		

		FTMAP ft1;
		pushtoVector<FTMAP>(&ft1, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		
		gettimeofday(&start, NULL);
		while (ft1.begin() != ft1.end())
			ft1.erase(ft1.begin());
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map key value erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		pushtoVector<STDMAP>(&std1, &v1);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		for (int i = 25; i < 49920; i++)
			v1.push_back(std1.erase(i));
		for (int i = 25; i < 49920; i++)
			v1.push_back(std1.erase(i));
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		

		FTMAP ft1;
		pushtoVector<FTMAP>(&ft1, &v2);
		for (int i = 0, j = 5; i < 50000; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		
		gettimeofday(&start, NULL);
		for (int i = 25; i < 49920; i++)
			v2.push_back(ft1.erase(i));
		for (int i = 25; i < 49920; i++)
			v2.push_back(ft1.erase(i));
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting map range erase:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			std1.insert(std::make_pair(i, j));
			std2.insert(std::make_pair(i, j));
		}
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		STDMAP::iterator stdit = std2.begin();
		for (int i = 0; i < 2000; i++)
			stdit++;
		gettimeofday(&start, NULL);
		std1.erase(std1.begin(), std1.end());
		std2.erase(stdit, std2.end());
		stdtime = gettime(start);
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		
		
		FTMAP ft1;
		FTMAP ft2;
		for (int i = 0, j = 5; i < 50000; i++, j++)
		{
			ft1.insert(ft::make_pair(i, j));
			ft2.insert(ft::make_pair(i, j));
		}
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		FTMAP::iterator ftit = ft2.begin();
		for (int i = 0; i < 2000; i++)
			ftit++;
		gettimeofday(&start, NULL);
		ft1.erase(ft1.begin(), ft1.end());
		ft2.erase(ftit, ft2.end());
		fttime = gettime(start);
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting map swap:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		STDMAP std2;
		for (int i = 0, j = 5; i < 5; i++, j++)
		{
			std1.insert(std::make_pair(i, j));
			std2.insert(std::make_pair(j, i));
		}
		
		STDMAP::iterator stdit1 = std1.begin();
		STDMAP::iterator stdit2 = std2.begin();
		v1.push_back(stdit1 == std1.begin());
		v1.push_back(stdit2 == std2.begin());
		v1.push_back(stdit1 == std2.begin());
		v1.push_back(stdit2 == std1.begin());
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		
		gettimeofday(&start, NULL);
		std1.swap(std2);
		stdtime = gettime(start);

		v1.push_back(stdit1 == std1.begin());
		v1.push_back(stdit2 == std2.begin());
		v1.push_back(stdit1 == std2.begin());
		v1.push_back(stdit2 == std1.begin());
		pushtoVector<STDMAP>(&std1, &v1);
		pushtoVector<STDMAP>(&std2, &v1);
		

		FTMAP ft1;
		FTMAP ft2;
		for (int i = 0, j = 5; i < 5; i++, j++)
		{
			ft1.insert(ft::make_pair(i, j));
			ft2.insert(ft::make_pair(j, i));
		}
		FTMAP::iterator ftit1 = ft1.begin();
		FTMAP::iterator ftit2 = ft2.begin();
		v2.push_back(ftit1 == ft1.begin());
		v2.push_back(ftit2 == ft2.begin());
		v2.push_back(ftit1 == ft2.begin());
		v2.push_back(ftit2 == ft1.begin());
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);
		
		gettimeofday(&start, NULL);
		ft1.swap(ft2);
		fttime = gettime(start);
		
		v2.push_back(ftit1 == ft1.begin());
		v2.push_back(ftit2 == ft2.begin());
		v2.push_back(ftit1 == ft2.begin());
		v2.push_back(ftit2 == ft1.begin());
		pushtoVector<FTMAP>(&ft1, &v2);
		pushtoVector<FTMAP>(&ft2, &v2);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting map count, find:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		STDMAP std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(std::make_pair(i, j));
		gettimeofday(&start, NULL);
		for (int i = -3; i < 8; i++)
			v1.push_back(std1.count(i));
		v1.push_back(std1.find(3)->first);
		v1.push_back(std1.find(1)->first);
		v1.push_back(std1.find(0)->first);
		v1.push_back((std1.find(4) == std1.end()));
		v1.push_back((std1.find(12) == std1.end()));
		stdtime = gettime(start);
		

		FTMAP ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		gettimeofday(&start, NULL);
		for (int i = -3; i < 8; i++)
			v2.push_back(ft1.count(i));
		v2.push_back(ft1.find(3)->first);
		v2.push_back(ft1.find(1)->first);
		v2.push_back(ft1.find(0)->first);
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

		STDMAP std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(std::make_pair(i, j));
		std1.insert(std::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v1.push_back(std1.equal_range(2).first->first);
		v1.push_back(std1.equal_range(2).first->second);
		v1.push_back(std1.equal_range(2).second->first);
		v1.push_back(std1.equal_range(2).second->second);
		v1.push_back(std1.equal_range(4).first->first);
		v1.push_back(std1.equal_range(4).first->second);
		v1.push_back(std1.equal_range(4).second->first);
		v1.push_back(std1.equal_range(4).second->second);
		v1.push_back(std1.equal_range(8).first->first);
		v1.push_back(std1.equal_range(8).first->second);
		v1.push_back(std1.equal_range(8).second->first);
		v1.push_back(std1.equal_range(8).second->second);
		v1.push_back(std1.equal_range(1234).first == std1.end());
		v1.push_back(std1.equal_range(1234).second == std1.end());
		stdtime = gettime(start);
		

		FTMAP ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		ft1.insert(ft::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v2.push_back(ft1.equal_range(2).first->first);
		v2.push_back(ft1.equal_range(2).first->second);
		v2.push_back(ft1.equal_range(2).second->first);
		v2.push_back(ft1.equal_range(2).second->second);
		v2.push_back(ft1.equal_range(4).first->first);
		v2.push_back(ft1.equal_range(4).first->second);
		v2.push_back(ft1.equal_range(4).second->first);
		v2.push_back(ft1.equal_range(4).second->second);
		v2.push_back(ft1.equal_range(8).first->first);
		v2.push_back(ft1.equal_range(8).first->second);
		v2.push_back(ft1.equal_range(8).second->first);
		v2.push_back(ft1.equal_range(8).second->second);
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

		STDMAP std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(std::make_pair(i, j));
		std1.insert(std::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v1.push_back(std1.lower_bound(2)->first);
		v1.push_back(std1.lower_bound(2)->second);
		v1.push_back(std1.lower_bound(2)->first);
		v1.push_back(std1.lower_bound(2)->second);
		v1.push_back(std1.lower_bound(4)->first);
		v1.push_back(std1.lower_bound(4)->second);
		v1.push_back(std1.lower_bound(4)->first);
		v1.push_back(std1.lower_bound(4)->second);
		v1.push_back(std1.lower_bound(8)->first);
		v1.push_back(std1.lower_bound(8)->second);
		v1.push_back(std1.lower_bound(8)->first);
		v1.push_back(std1.lower_bound(8)->second);
		v1.push_back(std1.lower_bound(1234) == std1.end());
		v1.push_back(std1.lower_bound(1234) == std1.end());
		stdtime = gettime(start);
		

		FTMAP ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		ft1.insert(ft::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v2.push_back(ft1.lower_bound(2)->first);
		v2.push_back(ft1.lower_bound(2)->second);
		v2.push_back(ft1.lower_bound(2)->first);
		v2.push_back(ft1.lower_bound(2)->second);
		v2.push_back(ft1.lower_bound(4)->first);
		v2.push_back(ft1.lower_bound(4)->second);
		v2.push_back(ft1.lower_bound(4)->first);
		v2.push_back(ft1.lower_bound(4)->second);
		v2.push_back(ft1.lower_bound(8)->first);
		v2.push_back(ft1.lower_bound(8)->second);
		v2.push_back(ft1.lower_bound(8)->first);
		v2.push_back(ft1.lower_bound(8)->second);
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

		STDMAP std1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			std1.insert(std::make_pair(i, j));
		std1.insert(std::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v1.push_back(std1.upper_bound(2)->first);
		v1.push_back(std1.upper_bound(2)->second);
		v1.push_back(std1.upper_bound(2)->first);
		v1.push_back(std1.upper_bound(2)->second);
		v1.push_back(std1.upper_bound(4)->first);
		v1.push_back(std1.upper_bound(4)->second);
		v1.push_back(std1.upper_bound(4)->first);
		v1.push_back(std1.upper_bound(4)->second);
		v1.push_back(std1.upper_bound(8)->first);
		v1.push_back(std1.upper_bound(8)->second);
		v1.push_back(std1.upper_bound(8)->first);
		v1.push_back(std1.upper_bound(8)->second);
		v1.push_back(std1.upper_bound(1234) == std1.end());
		v1.push_back(std1.upper_bound(1234) == std1.end());
		stdtime = gettime(start);
		

		FTMAP ft1;
		for (int i = 0, j = 5; i < 5; i++, j++)
			ft1.insert(ft::make_pair(i, j));
		ft1.insert(ft::make_pair(12, 5));
		gettimeofday(&start, NULL);
		v2.push_back(ft1.upper_bound(2)->first);
		v2.push_back(ft1.upper_bound(2)->second);
		v2.push_back(ft1.upper_bound(2)->first);
		v2.push_back(ft1.upper_bound(2)->second);
		v2.push_back(ft1.upper_bound(4)->first);
		v2.push_back(ft1.upper_bound(4)->second);
		v2.push_back(ft1.upper_bound(4)->first);
		v2.push_back(ft1.upper_bound(4)->second);
		v2.push_back(ft1.upper_bound(8)->first);
		v2.push_back(ft1.upper_bound(8)->second);
		v2.push_back(ft1.upper_bound(8)->first);
		v2.push_back(ft1.upper_bound(8)->second);
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

		STDMAP std1;
		STDMAP std2;

		gettimeofday(&start, NULL);
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std1.insert(std::make_pair(1,1));
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std2.insert(std::make_pair(3,3));
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std2.insert(std::make_pair(1,1));
		v1.push_back(std1 == std2);
		v1.push_back(std1 != std2);
		v1.push_back(std1 < std2);
		v1.push_back(std1 <= std2);
		v1.push_back(std1 > std2);
		v1.push_back(std1 >= std2);
		std1.insert(std::make_pair(3,3));
		stdtime = gettime(start);
		

		FTMAP ft1;
		FTMAP ft2;

		gettimeofday(&start, NULL);
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft1.insert(ft::make_pair(1,1));
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft2.insert(ft::make_pair(3,3));
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft2.insert(ft::make_pair(1,1));
		v2.push_back(ft1 == ft2);
		v2.push_back(ft1 != ft2);
		v2.push_back(ft1 < ft2);
		v2.push_back(ft1 <= ft2);
		v2.push_back(ft1 > ft2);
		v2.push_back(ft1 >= ft2);
		ft1.insert(ft::make_pair(3,3));
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
}