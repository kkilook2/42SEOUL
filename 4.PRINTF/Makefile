# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 02:39:36 by yoncho            #+#    #+#              #
#    Updated: 2021/02/07 11:37:46 by yoncho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_printf.c\
				ft_printf_utils.c

OBJS = $(subst .c,.o,$(FILES))

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
.PHONY : all clean fclean re

