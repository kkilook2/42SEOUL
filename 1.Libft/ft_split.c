/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 01:51:08 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/02 23:59:14 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		place_num(const char *str, char c)
{
	size_t			i;
	size_t			p_num;

	i = 0;
	p_num = 0;
	while (str[i] != 0)
	{
		if (str[i] != c && str[i] != 0)
		{
			p_num++;
			while (str[i] != c && str[i] != 0)
				i++;
		}
		else if (str[i] != 0)
			i++;
	}
	return (p_num);
}

static void			copy_str(char *dst, char const *src, int start, int end)
{
	int				i;

	i = 0;
	while (start < end)
	{
		dst[i] = src[start];
		i++;
		start++;
	}
	dst[i] = 0;
}

static void			*memory_out(char **d_mem, size_t cnt)
{
	size_t			i;

	i = 0;
	while (i < cnt)
	{
		free(d_mem[i]);
		i++;
	}
	free(d_mem);
	return (NULL);
}

static void			spliting(char const *s, char c, char **str)
{
	size_t			i;
	size_t			k;
	size_t			start;

	i = 0;
	k = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 0)
		{
			start = i;
			while (s[i] != c && s[i] != 0)
				i++;
			if ((str[k] = (char *)malloc(sizeof(char) * (i - start + 1))) == 0)
			{
				memory_out(str, k);
				return ;
			}
			copy_str(str[k], s, start, i);
			k++;
		}
		else if (s[i] != 0)
			i++;
	}
}

char				**ft_split(char const *s, char c)
{
	char			**str;
	size_t			n;

	if (!s)
		return (0);
	n = place_num(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (str == 0)
		return (0);
	str[n] = 0;
	if (n == 0)
		return (str);
	spliting(s, c, str);
	return (str);
}
