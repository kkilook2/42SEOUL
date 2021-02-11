/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:43:36 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/11 21:54:25 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char					*ft_get_char(char c)
{
	char				*ret;

	ret = (char *)malloc(sizeof(char) * 2);
	*ret = c;
	ret[1] = '\0';
	return (ret);
}

char					*ft_get_string(char *s)
{
	char				*ret;

	if (s == 0)
		return (ft_strdup("(null)"));
	ret = ft_strdup(s);
	return (ret);
}

char					*ft_get_integer(const char **format,
						unsigned long long i)
{
	char				*ret;
	char				*tmp;

	if (**format == 'u' && i < 0)
		return (0);
	tmp = ft_itoa(i);
	ret = ft_strdup(tmp);
	free((char*)tmp);
	return (ret);
}

char					*ft_get_pointer(unsigned long long i)
{
	char				*ret;
	char				*hexa_info;
	unsigned long long	p;
	int					len;
	char				*tmp;

	hexa_info = "0123456789abcdef";
	len = 0;
	p = i;
	while (p != 0)
	{
		p /= 16;
		len++;
	}
	ret = malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (i == 0)
		*ret = '0';
	while (i != 0)
	{
		ret[--len] = hexa_info[i % 16];
		i /= 16;
	}
	tmp = ft_strjoin("0x", ret);
	free(ret);
	return (tmp);
}

char					*ft_get_hexa(const char **format, unsigned int i)
{
	char				*ret;
	char				*hexa_info;
	unsigned int		unit_i;
	int					len;

	hexa_info = "0123456789abcdef";
	len = 0;
	unit_i = i;
	while (unit_i != 0)
	{
		unit_i /= 16;
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
	return (ret);
}
