/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 02:02:11 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/01 03:26:57 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			procces(char *str, int cnt, int nt)
{
	long long	n;

	n = nt;
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	str[cnt] = '\0';
	while (1)
	{
		str[cnt - 1] = n % 10 + '0';
		n = n / 10;
		if (!n)
			break ;
		cnt--;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			cnt;
	int			nt;

	nt = n;
	cnt = 1;
	if (n < 0)
		cnt = 2;
	while (1)
	{
		if (!(nt = nt / 10))
			break ;
		cnt++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (cnt + 1))))
		return (NULL);
	procces(str, cnt, n);
	return (str);
}
