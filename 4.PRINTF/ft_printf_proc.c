/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_proc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 21:08:31 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 21:09:34 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_proc_zero(const char **format, char *form_str, t_flags *flag)
{
	if (flag->zero)
	{
		if (flag->dot || **format == 'c' || **format == 's' || **format == 'p')
			ft_memset(form_str, ' ', flag->width);
		else if (!(flag->minus))
			ft_memset(form_str, '0', flag->width);
		else
			ft_memset(form_str, ' ', flag->width);
	}
	else
		ft_memset(form_str, ' ', flag->width);
}

char		*ft_proc_prec_str(char *form_str, t_flags *flag)
{
	int		len;
	char	*ret;

	len = ft_strlen(form_str);
	if (flag->prec == 0)
	{
		free(form_str);
		return (ft_strdup(""));
	}
	if (flag->prec < len)
	{
		ret = malloc(sizeof(char) * flag->prec + 1);
		ft_strlcpy(ret, form_str, (flag->prec + 1));
		ret[flag->prec] = '\0';
		free(form_str);
		return (ret);
	}
	return (form_str);
}

char		*ft_proc_prec(char *form_str, t_flags *flag)
{
	int		len;
	char	*ret;

	len = ft_strlen(form_str);
	if (len == 1 && *form_str == '0' && (flag->prec == 0))
		ret = ft_strdup("");
	else if (*form_str == '-' && (flag->prec > len - 1))
	{
		ret = malloc(sizeof(char) * flag->prec + 1);
		ft_memset(ret, '0', flag->prec + 1);
		*ret = '-';
		ft_strlcpy(ret + (flag->prec + 1 - (len - 1)),
					form_str + 1, flag->prec);
	}
	else if (flag->prec > len)
	{
		ret = malloc(sizeof(char) * flag->prec);
		ft_memset(ret, '0', flag->prec);
		ft_strlcpy(ret + (flag->prec - len), form_str, flag->prec);
	}
	else
		return (form_str);
	free(form_str);
	return (ret);
}

char		*ft_proc_width(const char **format, char *form_str, t_flags *flag)
{
	int		len;
	char	*ret;

	len = ft_strlen(form_str);
	if (*form_str == '\0' && **format == 'c')
		len = 1;
	if (flag->width > len)
	{
		ret = malloc(sizeof(char) * flag->width + 1);
		ret[flag->width] = '\0';
		ft_proc_zero(format, ret, flag);
		if (flag->minus)
			ft_memcpy(ret, form_str, len);
		else if (flag->zero && (!flag->dot) && *form_str == '-')
		{
			*ret = '-';
			ft_memcpy(ret + (flag->width - len + 1), form_str + 1, len);
		}
		else
			ft_memcpy(ret + (flag->width - len), form_str, len);
		free(form_str);
		return (ret);
	}
	return (form_str);
}
