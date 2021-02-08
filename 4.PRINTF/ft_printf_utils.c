/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:43:36 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/09 03:14:45 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strncpy(char *form_str, t_flags *flag)
{
  char	*ret;
  int	i;
  
  //printf("here is cpy = [ %s ]",  form_str);
  i = 0;
  while (i < flag->prec)
  {
	  ret[i] = form_str[i];
	  i++;
  }
  ret[i] = '\0';
  return ret;
}

char  *ft_cs_proc(char *form_str, t_flags *flag)
{
	char	*ret;
	int	form_len;
	int	i;
	int k;

	k = 0;
	ret = (char *)malloc(sizeof(flag->width));
	i = -1;
	form_len = ft_strlen(form_str);
	if (flag->minus)
	{
    while (++i < form_len)
      ret[i] = form_str[i];
    while (i < flag->width)
      ret[i++] = ' ';
	}
	else
	{
		while (++i < (flag->width) - form_len)
      ret[i] = ' ';
    while (i < flag->width)
      ret[i++] = form_str[k++];
	}
	return ret;
}

char  *ft_str_prec_width(char *form_str, t_flags *flag)
{
  char  *ret;


  return ret;
}

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
    return (ft_strdup(""));
  ret = ft_strdup(s);
  return ret;
}

char    *ft_get_integer(int i)
{
  char *ret;
  if (i == 0)
    return (ft_strdup(""));
  ret = ft_strdup(ft_itoa(i));
  return ret;
}