# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/13 13:20:40 by yoncho            #+#    #+#              #
#    Updated: 2021/06/13 19:40:32 by yoncho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex \
		pipex_utils \

SRCS = $(addsuffix .c, $(addprefix ./srcs/, $(SRC)))
OBJS = $(addsuffix .o, $(addprefix ./srcs/, $(SRC)))

.c.o:
	make -C srcs/libft
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) -o $(NAME) $(OBJS) -L./srcs/libft/ -lft

all: $(NAME)

clean:
	make clean -C srcs/libft
	rm -f $(OBJS)

fclean: clean
	make fclean -C srcs/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
