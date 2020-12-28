# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 15:50:13 by yoncho            #+#    #+#              #
#    Updated: 2020/12/28 21:21:13 by yoncho           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = ft_isalpha.c\
	ft_isascii.c\
	ft_isprint.c\
	ft_isdigit.c\
	ft_isalnum.c\
	ft_atoi.c\
	ft_toupper.c\
	ft_tolower.c\
	ft_strlen.c\
	ft_strlcpy.c\
	ft_strlcat.c\
	ft_strncmp.c\
	ft_strnstr.c\
	ft_strchr.c\
	ft_strrchr.c\
	ft_memset.c\
	ft_bzero.c\
	ft_memcpy.c

OBJS = $(subst .c,.o,$(FILES))

all : $(TARGET)

$(TARGET) : 
	$(CC) $(CFLAGS) -c $(FILES) libft.h
	ar rcs  $(TARGET) $(OBJS)

so :
	$(CC) -fPIC $(CFLAGS) -c $(FILES)
	gcc -shared -o libft.so $(OBJS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET) libft.so

re : fclean all
