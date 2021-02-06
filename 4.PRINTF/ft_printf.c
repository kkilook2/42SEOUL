/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:54:28 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/06 22:10:57 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    putchr(char s)
{
    write(1, &s, 1);
}

void  reset_flags(flags *flag)
{
    flag->minus = 0;
    flag->dot = 0;
    flag->prec = 0;
    flag->width = 0;
    flag->star = 0;
    flag->zero = 0;
}


int		ft_parse_char(flags *flag, va_list ap)
{
	int i;
	int	ret;
	
	if (flag->star == 1)
		i = va_arg(ap, int);
	else
		i = flag->width;
	ret = i;
	if (flag->minus == 1)
	{
		putchr(va_arg(ap, int));
		while(i-- > 1)
			putchr(' ');
	}
	else if (flag->minus == 0)
	{
		while(i-- > 1)
			putchr(' ');
		putchr(va_arg(ap, int));
	}
	if (ret == 0)
		return (1);
	return (ret);
}


int     ft_treatment(int c, flags *flag, va_list ap)
{
	int	len;

	len = 0;
	
	if (c == 'c')
	{
		len += ft_parse_char(flag, ap);
	}
	return (len);
}

int     ft_flag_parse(const char *format, int i, flags *flag, va_list ap)
{
    while (format[i])
    {
		if (!(ft_isdigit(format[i])) && !(ft_strchr("csdixX%up", format[i])) && !(ft_strchr("-0.*", format[i])))
			break;
		else if (format[i - 1] == '%' && format[i] == '0')
			flag->zero = 1;
		else if (format[i] =='-')
			flag->minus = 1;
		else if (format[i] == '*')
			flag->star = 1;
		else if ((!(flag->dot) && format[i] == '*') || ft_isdigit(format[i]))
			flag->width = (flag->width) * 10 + format[i] - '0';
		else if (format[i] == '.')
		{
			flag->dot = 1;
			flag->prec = format[i] - '0';
		}
		else if (ft_strchr("csdixXup", format[i]))
			return (i);
        i++;
    }
    return i;
}

int     ft_treat_format(const char *format, va_list ap, int len)
{
    int     i;
    flags  flag;
    
    i = 0;
    while (true)
    {
		reset_flags(&flag);
		if (format[i] == 0)
            break;
		if (format[i] == '%' && format[i + 1] == '%')
		{
			putchr('%');
			len++;
		}	
        else if (format[i] == '%' && format[i + 1] != '\0')
        {
            i = ft_flag_parse(format, i, &flag, ap);
            if (ft_strchr("csdixXu%p", format[i]))
                len += ft_treatment(format[i], &flag, ap);
            else if (format[i] != '\0')
            {
                putchr(format[i]);
                len++;
            }
        }
        else if (format[i] != '%')
        {
            putchr(format[i]);
            len++;
        }
        i++;
    }
    return (len);
}

int     ft_printf(const char *input, ...)
{
	va_list     ap;
    const char  *format;
    int         len;

    len = 0;
    format = ft_strdup(input);
    va_start(ap, input);
    if (*format)
        len += ft_treat_format(format, ap, len);
    va_end(ap);
    free((char *)format);
    return (len);
}  

int main()
{
	printf("%d", ft_printf("hello %-*c wo%%rld %-6c", 5,'a', 'b'));
	printf("\n");
	printf("%d", printf("hello %-*c wo%%rld %-6c", 5,'a', 'b'));
    return (0);
}