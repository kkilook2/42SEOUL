# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 02:39:36 by yoncho            #+#    #+#              #
#    Updated: 2021/02/10 21:15:29 by yoncho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
LIBFT	= ./libft

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

SRCS	= ft_printf.c\
		ft_printf_utils.c\
		ft_printf_format_utils.c\
		ft_printf_treat.c\
		ft_printf_proc.c

BSRCS	=

OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -I.

$(NAME) : $(OBJS)
	make -C $(LIBFT)
	cp $(LIBFT)/libft.a $(NAME)
	$(AR) $@ $^

bonus : $(BOBJS)
	$(AR) $(NAME) $^

all : $(NAME)

clean :
	make -C $(LIBFT) clean
	$(RM) $(OBJS) $(BOBJS)

fclean : clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)

re : clean all

.PHONY : all clean fclean re bonus
