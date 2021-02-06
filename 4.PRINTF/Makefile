# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/06 02:39:36 by yoncho            #+#    #+#              #
#    Updated: 2021/02/06 02:54:26 by yoncho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c/
			ft_printf_utils.c

$(NAME) : $(OBJS)
	$(AR) $@ $^ -L./libft -lft

