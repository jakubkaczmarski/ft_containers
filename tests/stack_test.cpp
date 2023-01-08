#include <stack>
#include <vector>
#include <deque>
#include <list>
#include "../stack.hpp"
#include "testing.hpp"
#define STDSTACK std::stack<int>
#define FTSTACK ft::stack<int>

int main()
{
	t_timeval start;
	int stdtime;
	int fttime;
	std::cout << "   _____ _______       _____ _  __" << std::endl;
	std::cout << "  / ____|__   __|/\\   / ____| |/ /" << std::endl;
	std::cout << " | (___    | |  /  \\ | |    | ' / " << std::endl;
	std::cout << "  \\___ \\   | | / /\\ \\| |    |  <  " << std::endl;
	std::cout << "  ____) |  | |/ ____ \\ |____| . \\ " << std::endl;
	std::cout << " |_____/   |_/_/    \\_\\_____|_|\\_\\" << std::endl;
	
	std::cout << "\nTesting stack constructors:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		gettimeofday(&start, NULL);
		STDSTACK std1;
		std::stack<int, std::vector<int> > std2;
		std::stack<int, std::deque<int> > std3;
		std::stack<int, std::list<int> > std4;
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std3.size());
		v1.push_back(std4.size());
		stdtime = gettime(start);

		gettimeofday(&start, NULL);
		FTSTACK ft1;
		ft::stack<int, std::vector<int> > ft2;
		ft::stack<int, std::deque<int> > ft3;
		ft::stack<int, std::list<int> > ft4;
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft3.size());
		v2.push_back(ft4.size());
		fttime = gettime(start);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
	std::cout << "\nTesting stack assignment:" << std::endl;
	{
		std::vector<int> v1;
		std::vector<int> v2;
		
		
		STDSTACK std1;
		STDSTACK std1_2;
		std::stack<int, std::vector<int> > std2;
		std::stack<int, std::vector<int> > std2_2;
		std::stack<int, std::deque<int> > std3;
		std::stack<int, std::deque<int> > std3_2;
		std::stack<int, std::list<int> > std4;
		std::stack<int, std::list<int> > std4_2;
		gettimeofday(&start, NULL);
		for (int i = 0; i < 123512; i++)
		{
			std1.push(i);
			std2.push(i+1);
			std3.push(i+2);
			std4.push(i+3);
		}
		for (int i = 0; i < 115123; i++)
		{
			std1_2.push(i * 2);
			std2_2.push(i * 42);
			std3_2.push(i * 3);
			std4_2.push(i * 7);
		}
		v1.push_back(std1.size());
		v1.push_back(std1.top());
		v1.push_back(std1_2.size());
		v1.push_back(std1_2.top());
		v1.push_back(std2.size());
		v1.push_back(std2.top());
		v1.push_back(std2_2.size());
		v1.push_back(std2_2.top());
		v1.push_back(std3.size());
		v1.push_back(std3.top());
		v1.push_back(std3_2.size());
		v1.push_back(std3_2.top());
		v1.push_back(std4.size());
		v1.push_back(std4.top());
		v1.push_back(std4_2.size());
		v1.push_back(std4_2.top());
		std1 = std1_2;
		std2 = std2_2;
		std3 = std3_2;
		std4 = std4_2;
		v1.push_back(std1.size());
		v1.push_back(std1.top());
		v1.push_back(std1_2.size());
		v1.push_back(std1_2.top());
		v1.push_back(std2.size());
		v1.push_back(std2.top());
		v1.push_back(std2_2.size());
		v1.push_back(std2_2.top());
		v1.push_back(std3.size());
		v1.push_back(std3.top());
		v1.push_back(std3_2.size());
		v1.push_back(std3_2.top());
		v1.push_back(std4.size());
		v1.push_back(std4.top());
		v1.push_back(std4_2.size());
		v1.push_back(std4_2.top());
		stdtime = gettime(start);

		
		FTSTACK ft1;
		FTSTACK ft1_2;
		ft::stack<int, std::vector<int> > ft2;
		ft::stack<int, std::vector<int> > ft2_2;
		ft::stack<int, std::deque<int> > ft3;
		ft::stack<int, std::deque<int> > ft3_2;
		ft::stack<int, std::list<int> > ft4;
		ft::stack<int, std::list<int> > ft4_2;
		gettimeofday(&start, NULL);
		for (int i = 0; i < 123512; i++)
		{
			ft1.push(i);
			ft2.push(i+1);
			ft3.push(i+2);
			ft4.push(i+3);
		}
		for (int i = 0; i < 115123; i++)
		{
			ft1_2.push(i * 2);
			ft2_2.push(i * 42);
			ft3_2.push(i * 3);
			ft4_2.push(i * 7);
		}
		v2.push_back(ft1.size());
		v2.push_back(ft1.top());
		v2.push_back(ft1_2.size());
		v2.push_back(ft1_2.top());
		v2.push_back(ft2.size());
		v2.push_back(ft2.top());
		v2.push_back(ft2_2.size());
		v2.push_back(ft2_2.top());
		v2.push_back(ft3.size());
		v2.push_back(ft3.top());
		v2.push_back(ft3_2.size());
		v2.push_back(ft3_2.top());
		v2.push_back(ft4.size());
		v2.push_back(ft4.top());
		v2.push_back(ft4_2.size());
		v2.push_back(ft4_2.top());
		ft1 = ft1_2;
		ft2 = ft2_2;
		ft3 = ft3_2;
		ft4 = ft4_2;
		v2.push_back(ft1.size());
		v2.push_back(ft1.top());
		v2.push_back(ft1_2.size());
		v2.push_back(ft1_2.top());
		v2.push_back(ft2.size());
		v2.push_back(ft2.top());
		v2.push_back(ft2_2.size());
		v2.push_back(ft2_2.top());
		v2.push_back(ft3.size());
		v2.push_back(ft3.top());
		v2.push_back(ft3_2.size());
		v2.push_back(ft3_2.top());
		v2.push_back(ft4.size());
		v2.push_back(ft4.top());
		v2.push_back(ft4_2.size());
		v2.push_back(ft4_2.top());
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting stack empty, size, top, push, pop:" << std::endl;
	{
		
		std::vector<int> v1;
		std::vector<int> v2;

		gettimeofday(&start, NULL);
		STDSTACK std1;
		std::stack<int, std::vector<int> > std2;
		std::stack<int, std::deque<int> > std3;
		std::stack<int, std::list<int> > std4;
		v1.push_back(std1.empty());
		v1.push_back(std2.empty());
		v1.push_back(std3.empty());
		v1.push_back(std4.empty());
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std3.size());
		v1.push_back(std4.size());
		std1.push(5);
		std2.push(5);
		std3.push(5);
		std4.push(5);
		v1.push_back(std1.empty());
		v1.push_back(std2.empty());
		v1.push_back(std3.empty());
		v1.push_back(std4.empty());
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std3.size());
		v1.push_back(std4.size());
		std1.push(7);
		v1.push_back(std1.top());
		std1.push(16);
		v1.push_back(std1.top());
		std1.push(9);
		v1.push_back(std1.top());
		std1.push(3);
		v1.push_back(std1.top());
		std1.push(2);
		v1.push_back(std1.top());
		v1.push_back(std1.size());
		std1.pop();
		v1.push_back(std1.top());
		std1.pop();
		v1.push_back(std1.top());
		std1.pop();
		v1.push_back(std1.top());
		std1.pop();
		v1.push_back(std1.top());
		std1.pop();
		v1.push_back(std1.top());
		stdtime = gettime(start);

		gettimeofday(&start, NULL);
		FTSTACK ft1;
		ft::stack<int, std::vector<int> > ft2;
		ft::stack<int, std::deque<int> > ft3;
		ft::stack<int, std::list<int> > ft4;
		v2.push_back(ft1.empty());
		v2.push_back(ft2.empty());
		v2.push_back(ft3.empty());
		v2.push_back(ft4.empty());
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft3.size());
		v2.push_back(ft4.size());
		ft1.push(5);
		ft2.push(5);
		ft3.push(5);
		ft4.push(5);
		v2.push_back(ft1.empty());
		v2.push_back(ft2.empty());
		v2.push_back(ft3.empty());
		v2.push_back(ft4.empty());
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft3.size());
		v2.push_back(ft4.size());
		ft1.push(7);
		v2.push_back(ft1.top());
		ft1.push(16);
		v2.push_back(ft1.top());
		ft1.push(9);
		v2.push_back(ft1.top());
		ft1.push(3);
		v2.push_back(ft1.top());
		ft1.push(2);
		v2.push_back(ft1.top());
		v2.push_back(ft1.size());
		ft1.pop();
		v2.push_back(ft1.top());
		ft1.pop();
		v2.push_back(ft1.top());
		ft1.pop();
		v2.push_back(ft1.top());
		ft1.pop();
		v2.push_back(ft1.top());
		ft1.pop();
		v2.push_back(ft1.top());
		fttime = gettime(start);


		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}

	std::cout << "\nTesting stack long push, long pop:" << std::endl;
	{
		std::vector<int> v1;
		std::vector<int> v2;
		
		
		STDSTACK std1;
		std::stack<int, std::vector<int> > std2;
		std::stack<int, std::deque<int> > std3;
		std::stack<int, std::list<int> > std4;
		gettimeofday(&start, NULL);
		for (int i = 0; i < 123512; i++)
		{
			std1.push(i);
			std2.push(i+1);
			std3.push(i+2);
			std4.push(i+3);
		}
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std3.size());
		v1.push_back(std4.size());
		v1.push_back(std1.top());
		v1.push_back(std2.top());
		v1.push_back(std3.top());
		v1.push_back(std4.top());
		for (int i = 0; i < 115123; i++)
		{
			std1.pop();
			std2.pop();
			std3.pop();
			std4.pop();
		}
		v1.push_back(std1.size());
		v1.push_back(std2.size());
		v1.push_back(std3.size());
		v1.push_back(std4.size());
		v1.push_back(std1.top());
		v1.push_back(std2.top());
		v1.push_back(std3.top());
		v1.push_back(std4.top());
		stdtime = gettime(start);

		
		FTSTACK ft1;
		ft::stack<int, std::vector<int> > ft2;
		ft::stack<int, std::deque<int> > ft3;
		ft::stack<int, std::list<int> > ft4;
		gettimeofday(&start, NULL);
		for (int i = 0; i < 123512; i++)
		{
			ft1.push(i);
			ft2.push(i+1);
			ft3.push(i+2);
			ft4.push(i+3);
		}
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft3.size());
		v2.push_back(ft4.size());
		v2.push_back(ft1.top());
		v2.push_back(ft2.top());
		v2.push_back(ft3.top());
		v2.push_back(ft4.top());
		for (int i = 0; i < 115123; i++)
		{
			ft1.pop();
			ft2.pop();
			ft3.pop();
			ft4.pop();
		}
		v2.push_back(ft1.size());
		v2.push_back(ft2.size());
		v2.push_back(ft3.size());
		v2.push_back(ft4.size());
		v2.push_back(ft1.top());
		v2.push_back(ft2.top());
		v2.push_back(ft3.top());
		v2.push_back(ft4.top());
		fttime = gettime(start);

		std::cout << "STD: " << stdtime << "ms FT: " << fttime << "ms ";
		compareVectors(v1, v2);
		std::cout << std::endl;
	}
	
}