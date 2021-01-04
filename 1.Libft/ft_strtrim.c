/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 18:11:01 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/01 01:49:15 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	front_inum(size_t i, size_t len, char const *s1, char const *set)
{
	size_t	front_i;

	front_i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
		{
			front_i = i;
			break ;
		}
		i++;
	}
	return (front_i);
}

static int	end_inum(size_t i, size_t len, char const *s1, char const *set)
{
	size_t	end_i;

	end_i = 0;
	while (len-- > i)
	{
		if (ft_strchr(set, s1[len]) == 0)
		{
			end_i = len + 1;
			break ;
		}
	}
	return (end_i);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	front_i;
	char	*str;
	size_t	len;
	size_t	end_i;
	size_t	i;

	front_i = 0;
	end_i = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	front_i = front_inum(i, len, s1, set);
	end_i = end_inum(i, len, s1, set);
	if (!(str = (char *)malloc(sizeof(char) * (end_i - front_i + 1))))
		return (0);
	while (front_i < end_i)
	{
		str[i] = s1[front_i];
		i++;
		front_i++;
	}
	str[i] = '\0';
	return (str);
}
