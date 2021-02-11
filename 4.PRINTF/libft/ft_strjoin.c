/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 17:05:53 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/11 22:09:11 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	k;

	i = 0;
	k = 0;
	if (!s1 || !s2)
		return (0);
	i = 0;
	if (!(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (0);
	while (s1[i])
	{
		str[k] = s1[i++];
		k++;
	}
	i = 0;
	while (s2[i])
	{
		str[k] = s2[i];
		i++;
		k++;
	}
	str[k] = 0;
	return (str);
}
