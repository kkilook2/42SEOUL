/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 20:08:16 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 00:54:27 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format_print(const char **format, char *form_str, t_flags *flag, int len)
{
	// int	_null;

	// _null = 0;
	// if (**format == 'c' && *form_str == 0)
	// 	_null = 1;
	//printf("[%s]", form_str);
	//printf("flag is | %d | %d | %d |\n", flag->dot, flag->width, flag->prec);
	if (flag->dot)
	{
		if (flag->prec < 0)
			flag->dot = 0;
		else if (**format == 's')
			form_str = ft_strncpy(form_str, flag);
		else if (**format == 'd' || **format == 'i' || **format == 'u' || **format == 'x' || **format == 'X' )
			form_str = ft_strncpy_int(form_str, flag);
		form_str = ft_proc_prec(format, form_str, flag);
	}
	if (flag->width)
		form_str = ft_proc_width(format, form_str, flag);
	form_str = ft_strdup(form_str);
	write(1, form_str, ft_strlen(form_str));
	len = ft_strlen(form_str);
	return (len);
}

char	*ft_proc_prec(const char **format, char *form_str, t_flags *flag)
{
	char	*ret;
	int		len;

	len = flag->prec - ft_strlen(form_str);
	if (len < 0) //정밀도보다 문자열 길이가 길때
	{	
		if (**format == 's')
			ret = ft_strncpy(form_str, flag);
		else
			ret = ft_strncpy_int(form_str, flag);
	}
	else //정밀도보다 문자열길이가 작을때
		ret = form_str;
	
	return ret;
}

char	*ft_proc_width(const char **format, char *form_str, t_flags *flag)
{
	char	*ret;
	
	if( (int)ft_strlen(form_str) > flag->width)
		return form_str;
	if (**format == 'c' || **format == 's')
		ret = ft_cs_proc(form_str, flag);
	if (**format == 'd' || **format == 'i')
		ret = ft_di_proc(form_str, flag);
	if (**format == 'x' || **format == 'X')
		ret = ft_di_proc(form_str, flag);
	if (**format == 'u' || **format == 'p')
		ret = "test";
		
	
	//printf("[%s]", ret);
	//ret = ft_strdup(form_str);
	return ret;
}

