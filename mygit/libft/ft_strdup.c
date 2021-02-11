/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:44:55 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/11 21:28:05 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*st;
	unsigned int		s_len;
	unsigned int		i;

	s_len = ft_strlen(s) + 1;
	if (!(st = (char *)malloc(s_len * sizeof(char))))
		return (0);
	i = 0;
	while (s[i])
	{
		st[i] = s[i];
		i++;
	}
	st[i] = 0;
	return (st);
}
