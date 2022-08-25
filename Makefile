# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jkaczmar <jkaczmar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/19 21:03:55 by jkaczmar          #+#    #+#              #
#    Updated: 2022/08/25 20:43:49 by jkaczmar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= program
CC		= g++
CFLAGS	= -Wall -Werror -Wextra -std=c++98

SRCS	= main.cpp

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

fclean:
	rm -f $(NAME)

re:	fclean all

.PHONY: all bonus fclean re