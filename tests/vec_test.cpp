
#include <vector>
#include "../vector.hpp"
#include "testing.hpp"
#define STDVECT std::vector<int>
#define FTVECT ft::vector<int>
int main()
{

	t_timeval start;
	int stdtime;
	int fttime;
	std::cout << " __      ________ _____ _______ ____  _____" << std::endl;
	std::cout << " \\ \\    / /  ____/ ____|__   __/ __ \\|  __ \\" << std::endl;
	std::cout << "  \\ \\  / /| |__ | |       | | | |  | | |__)|" << std::endl;
	std::cout << "   \\ \\/ / |  __|| |       | | | |  | |  _  /" << std::endl;
	std::cout << "    \\  /  | |___| |____   | | | |__| | | \\ \\" << std::endl;
	std::cout << "     \\/   |______\\_____|  |_|  \\____/|_|  \\_\\" << std::endl;
	std::cout << "\nTesting vector constructors:" << std::endl;
	{
		gettimeofday(&start, NULL);
		STDVECT std1(1000000);
		STDVECT std2(1000000, 12);
		STDVECT std3(std2);
		STDVECT std4(std2.begin(), std2.end());
		stdtime = gettime(start);

		gettimeofday(&start, NULL);
		FTVECT ft1(1000000);
		FTVECT ft2(1000000, 12);
		FTVECT ft3(ft2);
		FTVECT ft4(ft2.begin(), ft2.end());
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
	}
	{
		STDVECT v1;
		STDVECT v2;
		STDVECT::iterator it;	
		STDVECT std1;
		STDVECT std2(100);
		STDVECT std3(100,5);
		STDVECT std4(std3);
		STDVECT std5(std3.begin(), std3.end());
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		for (it = std2.begin(); it != std2.end(); it++) { v1.push_back(*it); }
		v1.push_back(std3.size());
		v1.push_back(std3.capacity());
		for (it = std3.begin(); it != std3.end(); it++) { v1.push_back(*it); }
		v1.push_back(std3.size());
		v1.push_back(std3.capacity());
		for (it = std4.begin(); it != std4.end(); it++) { v1.push_back(*it); }
		v1.push_back(std4.size());
		v1.push_back(std4.capacity());
		for (it = std5.begin(); it != std5.end(); it++) { v1.push_back(*it); }
		v1.push_back(std5.size());
		v1.push_back(std5.capacity());
		
		FTVECT::iterator itt;	
		FTVECT ft1;
		FTVECT ft2(100);
		FTVECT ft3(100,5);
		FTVECT ft4(ft3);
		FTVECT ft5(ft3.begin(), ft3.end());
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (itt = ft1.begin(); itt != ft1.end(); itt++) { v2.push_back(*itt); }
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		for (itt = ft2.begin(); itt != ft2.end(); itt++) { v2.push_back(*itt); }
		v2.push_back(ft3.size());
		v2.push_back(ft3.capacity());
		for (itt = ft3.begin(); itt != ft3.end(); itt++) { v2.push_back(*itt); }
		v2.push_back(ft3.size());
		v2.push_back(ft3.capacity());
		for (itt = ft4.begin(); itt != ft4.end(); itt++) { v2.push_back(*itt); }
		v2.push_back(ft4.size());
		v2.push_back(ft4.capacity());
		for (itt = ft5.begin(); itt != ft5.end(); itt++) { v2.push_back(*itt); }
		v2.push_back(ft5.size());
		v2.push_back(ft5.capacity());
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector assignment:" << std::endl;
	{
		STDVECT v1;
		STDVECT std1;
		STDVECT std2(10000);
		STDVECT std3;
		STDVECT std4(1234);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		v1.push_back(std3.size());
		v1.push_back(std3.capacity());
		v1.push_back(std4.size());
		v1.push_back(std4.capacity());
		gettimeofday(&start, NULL);
		std3 = std1;
		std4 = std2;
		stdtime = gettime(start);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		v1.push_back(std3.size());
		v1.push_back(std3.capacity());
		v1.push_back(std4.size());
		v1.push_back(std4.capacity());

		STDVECT v2;
		FTVECT ft1;
		FTVECT ft2(10000);
		FTVECT ft3;
		FTVECT ft4(1234);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		v2.push_back(ft3.size());
		v2.push_back(ft3.capacity());
		v2.push_back(ft4.size());
		v2.push_back(ft4.capacity());
		gettimeofday(&start, NULL);
		ft3 = ft1;
		ft4 = ft2;
		fttime = gettime(start);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		v2.push_back(ft3.size());
		v2.push_back(ft3.capacity());
		v2.push_back(ft4.size());
		v2.push_back(ft4.capacity());
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector assign function:" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;
		STDVECT std1;
		STDVECT std2(123);
		STDVECT std3;
		STDVECT::iterator stdit;
		FTVECT ft1;
		FTVECT ft2(123);
		FTVECT ft3;
		FTVECT::iterator ftit;
		for (int i = 0; i < 1234578; i++)
		{
			std3.push_back(i);
			ft3.push_back(i);
		}
		gettimeofday(&start, NULL);
		std1.assign(21, 8);
		std2.assign(std3.begin() + 123, std3.end() - 532);
		std3.assign(std1.begin(), std1.end());
		for(stdit = std1.begin(); stdit != std1.end(); stdit++) { v1.push_back(*stdit); }
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for(stdit = std2.begin(); stdit != std2.end(); stdit++) { v1.push_back(*stdit); }
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		for(stdit = std3.begin(); stdit != std3.end(); stdit++) { v1.push_back(*stdit); }
		v1.push_back(std3.size());
		v1.push_back(std3.capacity());
		stdtime = gettime(start);
		
		gettimeofday(&start, NULL);
		ft1.assign(21, 8);
		ft2.assign(ft3.begin() + 123, ft3.end() - 532);
		ft3.assign(ft1.begin(), ft1.end());
		for(ftit = ft1.begin(); ftit != ft1.end(); ftit++) { v2.push_back(*ftit); }
		v2.push_back(std1.size());
		v2.push_back(ft1.capacity());
		for(ftit = ft2.begin(); ftit != ft2.end(); ftit++) { v2.push_back(*ftit); }
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		for(ftit = ft3.begin(); ftit != ft3.end(); ftit++) { v2.push_back(*ftit); }
		v2.push_back(ft3.size());
		v2.push_back(ft3.capacity());

		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting vector at, [], front, back, data" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;
		STDVECT std1;
		FTVECT ft1;
		for (int i = 0; i < 12341; i++)
		{
			std1.push_back(i);
			ft1.push_back(i);
		}
		gettimeofday(&start, NULL);
		v1.push_back(std1.at(234));
		v1.push_back(std1.at(0));
		v1.push_back(std1.at(12340));
		v1.push_back(std1.at(3252));
		try
		{
			int temp = std1.at(12341);
			v1.push_back(temp);
		}
		catch(const std::out_of_range &oor)
		{
			v1.push_back(-1);
		}
		v1.push_back(std1[234]);
		v1.push_back(std1[0]);
		v1.push_back(std1[12340]);
		v1.push_back(std1[3252]);
		v1.push_back(std1.front());
		v1.push_back(std1.back());
		v1.push_back((&std1[0] == std1.data()));
		stdtime = gettime(start);

		gettimeofday(&start, NULL);
		v2.push_back(ft1.at(234));
		v2.push_back(ft1.at(0));
		v2.push_back(ft1.at(12340));
		v2.push_back(ft1.at(3252));
		try
		{
			int temp = ft1.at(12341);
			v2.push_back(temp);
		}
		catch(const std::out_of_range &oor)
		{
			v2.push_back(-1);
		}
		v2.push_back(ft1[234]);
		v2.push_back(ft1[0]);
		v2.push_back(ft1[12340]);
		v2.push_back(ft1[3252]);
		v2.push_back(ft1.front());
		v2.push_back(ft1.back());
		v2.push_back((&ft1[0] == ft1.data()));
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector iterators" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;
		STDVECT std1;
		STDVECT std2;
		std2.push_back(123);
		std2.push_back(-5);
		std2.push_back(6);
		std2.push_back(52);
		std2.push_back(3);
		STDVECT::iterator stdit;
		STDVECT::const_iterator stdcit;
		STDVECT::reverse_iterator stdrev;
		STDVECT::const_reverse_iterator stdcrev;
		FTVECT ft1;
		FTVECT ft2;
		ft2.push_back(123);
		ft2.push_back(-5);
		ft2.push_back(6);
		ft2.push_back(52);
		ft2.push_back(3);
		FTVECT::iterator ftit;
		FTVECT::const_iterator ftcit;
		FTVECT::reverse_iterator ftrev;
		FTVECT::const_reverse_iterator ftcrev;

		gettimeofday(&start, NULL);
		v1.push_back((std1.begin() == std1.end()));
		for (stdit = std2.begin(); stdit != std2.end(); stdit++)
			v1.push_back(*stdit);
		v1.push_back((stdit == std2.end()));
		v1.push_back(*(--stdit));

		for (stdcit = std2.begin(); stdcit != std2.end(); stdcit++)
			v1.push_back(*stdcit);
		v1.push_back((stdcit == std2.end()));
		v1.push_back(*(--stdcit));

		v1.push_back((std1.rbegin() == std1.rend()));
		for (stdrev = std2.rbegin(); stdrev != std2.rend(); stdrev++)
			v1.push_back(*stdrev);
		v1.push_back((stdrev == std2.rend()));
		v1.push_back(*(--stdrev));
		
		for (stdcrev = std2.rbegin(); stdcrev != std2.rend(); stdcrev++)
			v1.push_back(*stdcrev);
		v1.push_back((stdcrev == std2.rend()));
		v1.push_back(*(--stdcrev));
		stdtime = gettime(start);
		//ft
		gettimeofday(&start, NULL);
		v2.push_back((ft1.begin() == ft1.end()));
		for (ftit = ft2.begin(); ftit != ft2.end(); ftit++)
			v2.push_back(*ftit);
		v2.push_back((ftit == ft2.end()));
		v2.push_back(*(--ftit));

		for (ftcit = ft2.begin(); ftcit != ft2.end(); ftcit++)
			v2.push_back(*ftcit);
		v2.push_back((ftcit == ft2.end()));
		v2.push_back(*(--ftcit));

		v2.push_back((ft1.rbegin() == ft1.rend()));
		for (ftrev = ft2.rbegin(); ftrev != ft2.rend(); ftrev++)
			v2.push_back(*ftrev);
		v2.push_back((ftrev == ft2.rend()));
		v2.push_back(*(--ftrev));
		
		for (ftcrev = ft2.rbegin(); ftcrev != ft2.rend(); ftcrev++)
			v2.push_back(*ftcrev);
		v2.push_back((ftcrev == ft2.rend()));
		v2.push_back(*(--ftcrev));
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	std::cout << "\nTesting vector empty, size, max_size, capacity, reserve" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;
		STDVECT std1;
		STDVECT std2(25);
		FTVECT ft1;
		FTVECT ft2(25);
		
		gettimeofday(&start, NULL);
		v1.push_back(std1.empty());
		v1.push_back(std2.empty());
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std1.max_size());
		v1.push_back(std1.max_size());
		v1.push_back(std2.capacity());
		v1.push_back(std2.capacity());
		std1.reserve(123);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		std2.reserve(5);
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		for (STDVECT::iterator it = std2.begin(); it != std2.end(); it++) { v1.push_back(*it); }
		std2.reserve(123);
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		for (STDVECT::iterator it = std2.begin(); it != std2.end(); it++) { v1.push_back(*it); }
		stdtime = gettime(start);
		
		gettimeofday(&start, NULL);
		v2.push_back(ft1.empty());
		v2.push_back(ft2.empty());
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft1.max_size());
		v2.push_back(ft1.max_size());
		v2.push_back(ft2.capacity());
		v2.push_back(ft2.capacity());
		ft1.reserve(123);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		ft2.reserve(5);
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		for (FTVECT::iterator it = ft2.begin(); it != ft2.end(); it++) { v2.push_back(*it); }
		ft2.reserve(123);
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		for (FTVECT::iterator it = ft2.begin(); it != ft2.end(); it++) { v2.push_back(*it); }
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector clear" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		STDVECT std2;
		for (int i = 0; i < 1234567; i++)
			std2.push_back(i);
		gettimeofday(&start, NULL);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		std1.clear();
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		std2.clear();
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		stdtime = gettime(start);

		//ft
		FTVECT ft1;
		FTVECT ft2;
		for (int i = 0; i < 1234567; i++)
			ft2.push_back(i);
		gettimeofday(&start, NULL);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		ft1.clear();
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		ft2.clear();
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	std::cout << "\nTesting vector single element insert" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		STDVECT std2;

		FTVECT ft1;
		FTVECT ft2;
		gettimeofday(&start, NULL);
		for (int i = 0; i < 12345; i++)
		{
			std1.insert(std1.begin(), i);
			std2.insert(std2.end(), i);
		}
		v1.push_back(*std1.insert(std1.begin(), -1));
		v1.push_back(*std1.insert(std1.begin() + 1234, -1));
		v1.push_back(*std1.insert(std1.end(), -1));
		v1.push_back(*std1.insert(std1.end() - 5123, -1));
		stdtime = gettime(start);
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		for (STDVECT::iterator it = std2.begin(); it != std2.end(); it++) { v1.push_back(*it); }
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		
		gettimeofday(&start, NULL);
		for (int i = 0; i < 12345; i++)
		{
			ft1.insert(ft1.begin(), i);
			ft2.insert(ft2.end(), i);
		}
		v2.push_back(*ft1.insert(ft1.begin(), -1));
		v2.push_back(*ft1.insert(ft1.begin() + 1234, -1));
		v2.push_back(*ft1.insert(ft1.end(), -1));
		v2.push_back(*ft1.insert(ft1.end() - 5123, -1));
		fttime = gettime(start);
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		for (FTVECT::iterator it = ft2.begin(); it != ft2.end(); it++) { v2.push_back(*it); }
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	std::cout << "\nTesting vector fill insert" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		
		FTVECT ft1;
		gettimeofday(&start, NULL);
		std1.insert(std1.begin(), 5, 5);
		std1.insert(std1.begin() + 2, 4, 4);
		std1.insert(std1.begin() + 4, 3, 3);
		std1.insert(std1.begin() + 5, 2, 2);
		std1.insert(std1.begin() + 6, 4234567, 2);
		stdtime = gettime(start);
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		
		//ft
		gettimeofday(&start, NULL);
		ft1.insert(ft1.begin(), 5, 5);
		ft1.insert(ft1.begin() + 2, 4, 4);
		ft1.insert(ft1.begin() + 4, 3, 3);
		ft1.insert(ft1.begin() + 5, 2, 2);
		ft1.insert(ft1.begin() + 6, 4234567, 2);
		fttime = gettime(start);
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	std::cout << "\nTesting vector range insert" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		STDVECT std2;

		FTVECT ft1;
		FTVECT ft2;


		for (int i = 0; i < 123456; i++) { std1.push_back(i); }
		gettimeofday(&start, NULL);
		std2.insert(std2.end(), std1.begin(), std1.end());
		std2.insert(std2.begin() + 5, std1.begin() + 7, std1.end() - 12);
		std2.insert(std2.begin() + 5, std2.begin() + 7, std2.end() - 12);
		std2.insert(std2.begin() + 5, std1.begin() + 55, std1.begin() + 55);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		v1.push_back(std2.size());
		v1.push_back(std2.capacity());
		for (STDVECT::iterator it = std2.begin(); it != std2.end(); it++) { v1.push_back(*it); }
		stdtime = gettime(start);


		for (int i = 0; i < 123456; i++) { ft1.push_back(i); }
		gettimeofday(&start, NULL);
		ft2.insert(ft2.end(), ft1.begin(), ft1.end());
		ft2.insert(ft2.begin() + 5, ft1.begin() + 7, ft1.end() - 12);
		ft2.insert(ft2.begin() + 5, ft2.begin() + 7, ft2.end() - 12);
		ft2.insert(ft2.begin() + 5, ft1.begin() + 55, ft1.begin() + 55);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		v2.push_back(ft2.size());
		v2.push_back(ft2.capacity());
		for (FTVECT::iterator it = ft2.begin(); it != ft2.end(); it++) { v2.push_back(*it); }
		fttime = gettime(start);
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector single erase" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;

		FTVECT ft1;
		
		for (int i = 0; i < 12345; i++) { std1.push_back(i); }
		gettimeofday(&start, NULL);
		v1.push_back(*std1.erase(std1.begin() + 5));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(*std1.erase(std1.begin() + 17));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(*std1.erase(std1.begin() + 28));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		while (std1.size() > 1)
			v1.push_back(*std1.erase(std1.begin()));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		std1.erase(std1.begin());
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		stdtime = gettime(start);

		
		for (int i = 0; i < 12345; i++) { ft1.push_back(i); }
		gettimeofday(&start, NULL);
		v2.push_back(*ft1.erase(ft1.begin() + 5));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(*ft1.erase(ft1.begin() + 17));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(*ft1.erase(ft1.begin() + 28));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		while (ft1.size() > 1)
			v2.push_back(*ft1.erase(ft1.begin()));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		ft1.erase(ft1.begin());
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting vector range erase" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;

		FTVECT ft1;

		for (int i = 0; i < 1234567; i++) { std1.push_back(i); }
		gettimeofday(&start, NULL);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(*std1.erase(std1.begin() + 25, std1.begin() + 7752));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(*std1.erase(std1.begin() + 5, std1.begin() + 12357));
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		v1.push_back(*std1.erase(std1.begin() + 5, std1.begin() + 6));
		std1.erase(std1.end() - 2555, std1.end());
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		std1.erase(std1.begin(), std1.end());
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		stdtime = gettime(start);
		
		for (int i = 0; i < 1234567; i++) { ft1.push_back(i); }
		gettimeofday(&start, NULL);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(*ft1.erase(ft1.begin() + 25, ft1.begin() + 7752));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(*ft1.erase(ft1.begin() + 5, ft1.begin() + 12357));
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		v2.push_back(*ft1.erase(ft1.begin() + 5, ft1.begin() + 6));
		ft1.erase(ft1.end() - 2555, ft1.end());
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		ft1.erase(ft1.begin(), ft1.end());
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		fttime = gettime(start);
		
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting vector push_back" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;

		FTVECT ft1;

		for (int i = 0; i < 1234567; i++) { std1.push_back(i); }
		gettimeofday(&start, NULL);
		for (int i = 0; i < 1234560; i++)
			std1.pop_back();
		stdtime = gettime(start);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());

		for (int i = 0; i < 1234567; i++) { ft1.push_back(i); }
		gettimeofday(&start, NULL);
		for (int i = 0; i < 1234560; i++)
			ft1.pop_back();
		fttime = gettime(start);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting vector pop_back" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;

		FTVECT ft1;

		gettimeofday(&start, NULL);
		for (int i = 0; i < 1234567; i++) { std1.push_back(i); }
		stdtime = gettime(start);
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());

		gettimeofday(&start, NULL);
		for (int i = 0; i < 1234567; i++) { ft1.push_back(i); }
		fttime = gettime(start);
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		
		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting vector resize" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;

		FTVECT ft1;

		for (int i = 0; i < 1234; i++) { std1.push_back(i); }
		gettimeofday(&start, NULL);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		std1.resize(52);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		std1.resize(5555);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		std1.resize(0);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		std1.resize(12345);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }
		std1.resize(1234);
		v1.push_back(std1.size());
		v1.push_back(std1.capacity());
		for (STDVECT::iterator it = std1.begin(); it != std1.end(); it++) { v1.push_back(*it); }

		stdtime = gettime(start);


		for (int i = 0; i < 1234; i++) { ft1.push_back(i); }
		gettimeofday(&start, NULL);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		ft1.resize(52);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		ft1.resize(5555);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		ft1.resize(0);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		ft1.resize(12345);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		ft1.resize(1234);
		v2.push_back(ft1.size());
		v2.push_back(ft1.capacity());
		for (FTVECT::iterator it = ft1.begin(); it != ft1.end(); it++) { v2.push_back(*it); }
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting vector swap" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		STDVECT std2;

		FTVECT ft1;
		FTVECT ft2;

		for (int i = 0; i < 1234; i++)
		{ 
			std1.push_back(i); 
			std2.push_back(5000 - i); 
		}
		STDVECT::iterator stdit1 = std1.begin();
		STDVECT::iterator stdit2 = std2.begin();
		int &stdref1 = std1.front();
		int &stdref2 = std2.front();
		v1.push_back((stdit1 == std1.begin()));
		v1.push_back((stdit2 == std2.begin()));
		v1.push_back((stdit1 == std2.begin()));
		v1.push_back((stdit2 == std1.begin()));
		v1.push_back((stdref1 == std1.front()));
		v1.push_back((stdref2 == std2.front()));
		v1.push_back((stdref1 == std2.front()));
		v1.push_back((stdref2 == std1.front()));
		gettimeofday(&start, NULL);
		std1.swap(std2);
		stdtime = gettime(start);
		v1.push_back((stdit1 == std1.begin()));
		v1.push_back((stdit2 == std2.begin()));
		v1.push_back((stdit1 == std2.begin()));
		v1.push_back((stdit2 == std1.begin()));
		v1.push_back((stdref1 == std1.front()));
		v1.push_back((stdref2 == std2.front()));
		v1.push_back((stdref1 == std2.front()));
		v1.push_back((stdref2 == std1.front()));
		

		for (int i = 0; i < 1234; i++)
		{
			ft1.push_back(i);
			ft2.push_back(5000 - i);
		}
		FTVECT::iterator ftit1 = ft1.begin();
		FTVECT::iterator ftit2 = ft2.begin();
		int &ftref1 = ft1.front();
		int &ftref2 = ft2.front();
		v2.push_back((ftit1 == ft1.begin()));
		v2.push_back((ftit2 == ft2.begin()));
		v2.push_back((ftit1 == ft2.begin()));
		v2.push_back((ftit2 == ft1.begin()));
		v2.push_back((ftref1 == ft1.front()));
		v2.push_back((ftref2 == ft2.front()));
		v2.push_back((ftref1 == ft2.front()));
		v2.push_back((ftref2 == ft1.front()));
		gettimeofday(&start, NULL);
		ft1.swap(ft2);
		fttime = gettime(start);
		v2.push_back((ftit1 == ft1.begin()));
		v2.push_back((ftit2 == ft2.begin()));
		v2.push_back((ftit1 == ft2.begin()));
		v2.push_back((ftit2 == ft1.begin()));
		v2.push_back((ftref1 == ft1.front()));
		v2.push_back((ftref2 == ft2.front()));
		v2.push_back((ftref1 == ft2.front()));
		v2.push_back((ftref2 == ft1.front()));


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	std::cout << "\nTesting vector relational operators" << std::endl;
	{
		STDVECT v1;
		STDVECT v2;

		STDVECT std1;
		STDVECT std2;

		FTVECT ft1;
		FTVECT ft2;


		gettimeofday(&start, NULL);
		v1.push_back((std1 == std2));
		v1.push_back((std1 != std2));
		v1.push_back((std1 < std2));
		v1.push_back((std1 <= std2));
		v1.push_back((std1 > std2));
		v1.push_back((std1 >= std2));
		std1.push_back(1);
		v1.push_back((std1 == std2));
		v1.push_back((std1 != std2));
		v1.push_back((std1 < std2));
		v1.push_back((std1 <= std2));
		v1.push_back((std1 > std2));
		v1.push_back((std1 >= std2));
		std2.push_back(1);
		v1.push_back((std1 == std2));
		v1.push_back((std1 != std2));
		v1.push_back((std1 < std2));
		v1.push_back((std1 <= std2));
		v1.push_back((std1 > std2));
		v1.push_back((std1 >= std2));
		std1.push_back(5);
		v1.push_back((std1 == std2));
		v1.push_back((std1 != std2));
		v1.push_back((std1 < std2));
		v1.push_back((std1 <= std2));
		v1.push_back((std1 > std2));
		v1.push_back((std1 >= std2));
		std1.erase(std1.begin());
		v1.push_back((std1 == std2));
		v1.push_back((std1 != std2));
		v1.push_back((std1 < std2));
		v1.push_back((std1 <= std2));
		v1.push_back((std1 > std2));
		v1.push_back((std1 >= std2));
		stdtime = gettime(start);

		gettimeofday(&start, NULL);
		v2.push_back((ft1 == ft2));
		v2.push_back((ft1 != ft2));
		v2.push_back((ft1 < ft2));
		v2.push_back((ft1 <= ft2));
		v2.push_back((ft1 > ft2));
		v2.push_back((ft1 >= ft2));
		ft1.push_back(1);
		v2.push_back((ft1 == ft2));
		v2.push_back((ft1 != ft2));
		v2.push_back((ft1 < ft2));
		v2.push_back((ft1 <= ft2));
		v2.push_back((ft1 > ft2));
		v2.push_back((ft1 >= ft2));
		ft2.push_back(1);
		v2.push_back((ft1 == ft2));
		v2.push_back((ft1 != ft2));
		v2.push_back((ft1 < ft2));
		v2.push_back((ft1 <= ft2));
		v2.push_back((ft1 > ft2));
		v2.push_back((ft1 >= ft2));
		ft1.push_back(5);
		v2.push_back((ft1 == ft2));
		v2.push_back((ft1 != ft2));
		v2.push_back((ft1 < ft2));
		v2.push_back((ft1 <= ft2));
		v2.push_back((ft1 > ft2));
		v2.push_back((ft1 >= ft2));
		ft1.erase(ft1.begin());
		v2.push_back((ft1 == ft2));
		v2.push_back((ft1 != ft2));
		v2.push_back((ft1 < ft2));
		v2.push_back((ft1 <= ft2));
		v2.push_back((ft1 > ft2));
		v2.push_back((ft1 >= ft2));

		fttime = gettime(start);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

}