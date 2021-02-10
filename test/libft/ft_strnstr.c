/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 19:21:03 by yoncho            #+#    #+#             */
/*   Updated: 2020/12/28 05:18:05 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	if (little[i] == 0)
		return ((char *)big);
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			k = 0;
			while (little[k] && k + i < len)
			{
				if (big[i + k] != little[k])
					break ;
				k++;
			}
			if (little[k] == 0)
				return ((char *)(big + i));
		}
		i++;
	}
	return (NULL);
}
