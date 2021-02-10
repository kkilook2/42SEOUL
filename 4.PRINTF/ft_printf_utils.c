/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:43:36 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 17:55:23 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int		ft_treat_width(const char **format, va_list ap, t_flags *flag)
{
  int  width;

  width = 0;
  if (**format == '*')
  {
    width += va_arg(ap, int);
    if (width < 0)
    {
      flag->minus = 1;
      width *= -1;
    }
    return (width);
  }
  while (ft_isdigit(**format))
  {
    width *= 10;
    width += (**format) - '0';
    (*format)++;
  }
  (*format)--;
  return (width);
}

int   ft_treat_prec(const char **format, va_list ap)
{
  int  prec;

  prec = 0;
  (*format)++;
  if (**format == '*')
    prec += va_arg(ap, int);
  while (ft_isdigit(**format))
  {
    prec *= 10;
    prec += (**format) - '0';
    (*format)++;
  }
  (*format)--;
  return (prec);
}

int   check_format(const char **format)
{
  if (**format == 'c' || **format == 's' || **format == 'd' ||
      **format == 'i' || **format == 'u' || **format == 'p' ||
      **format == 'x' || **format == 'X' || **format == '%')
			return (1);
  return (0);
}

char    *ft_get_char(char c)
{
  char *ret;
  
  ret = (char *)malloc(sizeof(char) * 2);
  *ret = c;
  ret[1] = '\0';
  return ret;
}

char    *ft_get_string(char *s)
{
	char *ret;
	
	if (s == 0)
    	return (ft_strdup("(null)"));
	ret = ft_strdup(s);
	return ret;
}

char    *ft_get_integer(const char **format, unsigned long long i)
{
	char *ret;
	
	if (**format == 'u' && i < 0)
		return (0);
	ret = ft_strdup(ft_itoa(i));
	return ret;
}

char	*ft_get_pointer(unsigned long long i)
{
	char	*ret;
	char	*hexa_info;
	unsigned long long p;
	int		len;
	
	hexa_info = "0123456789abcdef";
	len = 0;
	p = i;
	while ( p != 0)
	{
		p /= 16;
		len++;
	}
	ret = malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (i == 0)
		*ret = '0';
	while ( i != 0)
	{
		ret[--len] = hexa_info[p % 16];
		p /= 16;
	}
	ret = ft_strjoin("0x", ret);
	return (ret);
}

char    *ft_get_hexa(const char **format, unsigned int i)
{
	char	*ret;
	char	*hexa_info;
	unsigned int len_i;
	int		len;
	
	hexa_info = "0123456789abcdef";
	len = 0;
	len_i = i;
	while (len_i != 0)
	{
		len_i /= 16;
		len++;
	}
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (i == 0)
		ret[len] = '0';
	while (i != 0)
	{
		ret[--len] = hexa_info[i % 16];
		if (**format == 'X')
			ret[len] = ft_toupper(ret[len]);
		i /= 16;
	}
  	return ret;
}

