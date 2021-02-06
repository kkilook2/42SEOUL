/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/30 21:44:55 by yoncho            #+#    #+#             */
/*   Updated: 2020/12/31 01:01:39 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*st;
	int		s_len;
	int		i;

	i = 0;
	s_len = ft_strlen(s) + 1;
	st = (char *)malloc(s_len * sizeof(char));
	if (!st)
		return (NULL);
	while (i < s_len)
	{
		st[i] = s[i];
		i++;
	}
	st[i] = '\0';
	return (st);
	free(st);
}
