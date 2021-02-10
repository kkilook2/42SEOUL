/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:22:23 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 16:04:39 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_PRINTF_H 
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct s_flags {
	int		minus; // - 는 왼쪽 정렬
	int		zero; //0으로 채운다
	int		dot;   
	int		width; //폭
	int		prec;  //정밀도
	int		star;
}				t_flags;

int		ft_printf(const char *format, ...);
int		ft_format_print(const char **format, char *form_str, t_flags *flag, int len);

int		ft_print_char(char *form_str, t_flags *flag, va_list ap, int len);

char	*ft_proc_width(const char **format, char *form_str, t_flags *flag);
char	*ft_proc_prec(char *form_str,t_flags *flag);


char    *ft_get_char(char c);
char    *ft_get_string(char *s);
char    *ft_get_integer(const char **format, unsigned long long i);
char    *ft_get_hexa(const char **format, unsigned int i);
char	*ft_get_pointer(unsigned long long i);

void	putchr(char s);
void	ft_init_flags(t_flags *flag);
int		check_format(const char **format);
int		ft_treat_width(const char **format, va_list ap, t_flags *flag);
int		ft_treat_prec(const char **format, va_list ap);



int		ft_print_formstr(char *form_str, int _null, t_flags *flag);
void	ft_proc_zero(const char **format, char *form_str, t_flags *flag);
char	*ft_proc_prec_str(char *form_str, t_flags *flag);

#endif