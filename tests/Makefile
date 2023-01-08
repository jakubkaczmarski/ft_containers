# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/08 01:02:05 by jkaczmar          #+#    #+#              #
#    Updated: 2023/01/08 01:04:26 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	containers

SRCS		=	main.cpp

CC			=	c++

RM			=	rm

CFLAGS		=	-Wall -Wextra -Werror -std=c++98 -g

all:		
	sh exec.sh

vector:
	$(CC) $(CFLAGS) -o $(NAME) vector_tests.cpp && leaks --atExit -- ./$(NAME)

map:
	$(CC) $(CFLAGS) -o $(NAME) map_tests.cpp && leaks --atExit -- ./$(NAME)

stack:
	$(CC) $(CFLAGS) -o $(NAME) stack_tests.cpp && leaks --atExit -- ./$(NAME)
	
# set:
	# $(CC) $(CFLAGS) -o $(NAME) set_tests.cpp && leaks --atExit -- ./$(NAME)

clean:		
			$(RM) -f $(NAME)

fclean:		clean

re:			fclean all

.PHONY:		all clean fclean re vector map stack set