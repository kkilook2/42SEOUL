/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_treat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:03:16 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 21:04:22 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_treat_width(const char **format,
						va_list ap, t_flags *flag)
{
	int					width;

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

int						ft_treat_prec(const char **format, va_list ap)
{
	int					prec;

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
