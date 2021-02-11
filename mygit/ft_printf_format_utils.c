/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:08:16 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/11 21:55:44 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			check_format(const char **format)
{
	if (**format == 'c' || **format == 's' || **format == 'd' ||
		**format == 'i' || **format == 'u' || **format == 'p' ||
		**format == 'x' || **format == 'X' || **format == '%')
		return (1);
	return (0);
}

int			ft_print_formstr(char *form_str, int is_null, t_flags *flag)
{
	int		len;

	len = ft_strlen(form_str);
	if (is_null)
	{
		if (flag->width)
		{
			write(1, form_str, flag->width);
			len = flag->width;
		}
		else
		{
			write(1, form_str, 1);
			len = 1;
		}
	}
	else
		write(1, form_str, len);
	free(form_str);
	return (len);
}

int			ft_format_print(const char **format,
			char *form_str, t_flags *flag, int len)
{
	int		is_null;

	is_null = 0;
	if (**format == 'c' && *form_str == 0)
		is_null = 1;
	if (flag->dot)
	{
		if (flag->prec < 0)
			flag->dot = 0;
		else if (**format == 'd' || **format == 'i' || **format == 'u'
				| **format == 'x' || **format == 'X')
			form_str = ft_proc_prec(form_str, flag);
		else if (**format == 's')
			form_str = ft_proc_prec_str(form_str, flag);
	}
	if (flag->width)
		form_str = ft_proc_width(format, form_str, flag);
	len = ft_print_formstr(form_str, is_null, flag);
	return (len);
}
