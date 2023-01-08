c++ -Wall -Werror -Wextra -std=c++98 vec_test.cpp && leaks --atExit -- ./a.out
c++ -Wall -Werror -Wextra -std=c++98 map_test.cpp && leaks --atExit -- ./a.out
c++ -Wall -Werror -Wextra -std=c++98 stack_test.cpp && leaks --atExit -- ./a.out
# c++ -Wall -Werror -Wextra -std=c++98 set_t.cpp && leaks --atExit -- ./a.out