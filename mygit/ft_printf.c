/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 19:54:28 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/11 21:56:58 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_init_flags(t_flags *flag)
{
	flag->minus = 0;
	flag->dot = 0;
	flag->prec = 0;
	flag->width = 0;
	flag->zero = 0;
}

char			*ft_format_parse(const char **format, va_list ap)
{
	char		*ret;

	ret = 0;
	if (**format == 'c')
		ret = ft_get_char(va_arg(ap, int));
	else if (**format == '%')
		ret = ft_get_char('%');
	else if (**format == 's')
		ret = ft_get_string(va_arg(ap, char*));
	else if (**format == 'u')
		ret = ft_get_integer(format, va_arg(ap, unsigned int));
	else if (**format == 'd' || **format == 'i')
		ret = ft_get_integer(format, va_arg(ap, int));
	else if (**format == 'x' || **format == 'X')
		ret = ft_get_hexa(format, va_arg(ap, unsigned int));
	else if (**format == 'p')
		ret = ft_get_pointer(va_arg(ap, unsigned long long));
	return (ret);
}

void			ft_flag_parse(const char **format, t_flags *flag, va_list ap)
{
	while (!check_format(format))
	{
		if (**format == '0')
			flag->zero = 1;
		else if (**format == '-')
			flag->minus = 1;
		else if (!(flag->dot) && (**format == '*' || ft_isdigit(**format)))
			flag->width = ft_treat_width(format, ap, flag);
		else if (**format == '.')
		{
			flag->dot = 1;
			flag->prec = ft_treat_prec(format, ap);
		}
		else if (!(ft_strchr(".-0*", **format)))
			ft_putchar_fd(**format, 1);
		(*format)++;
	}
}

int				ft_treat_format(const char *format, va_list ap, int len)
{
	char		*form_str;
	t_flags		*flag;

	flag = malloc(sizeof(t_flags));
	ft_init_flags(flag);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			ft_flag_parse(&format, flag, ap);
			form_str = ft_format_parse(&format, ap);
			len += ft_format_print(&format, form_str, flag, len);
			ft_init_flags(flag);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			len++;
		}
		format++;
	}
	free(flag);
	return (len);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	len = 0;
	va_start(ap, format);
	if (*format)
		len += ft_treat_format(format, ap, len);
	va_end(ap);
	return (len);
}
