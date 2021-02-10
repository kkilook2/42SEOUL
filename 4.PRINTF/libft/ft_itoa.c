/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 02:02:11 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/10 17:44:18 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long	ft_abs(long long n)
{
	long long	num;

	num = n;
	if (n < 0)
		num = num * (-1);
	return (num);
}

int			ft_sizecheck(long long n)
{
	long long		num;
	unsigned int	count;

	count = 0;
	num = ft_abs(n);
	if (n == 0)
		count++;
	while (num > 0)
	{
		num = (num / 10);
		count++;
	}
	return (count);
}

char		*ft_itoa(long long n)
{
	char			*str;
	unsigned int	i;
	unsigned int	size;
	long long		nbr;

	size = ft_sizecheck(n);
	i = 1;
	nbr = ft_abs(n);
	if (n < 0)
		size++;
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	if (n < 0)
		str[0] = '-';
	while (i <= size)
	{
		if (str[size - i] != '-')
			str[size - i] = (nbr % 10) + '0';
		nbr = nbr / 10;
		i++;
	}
	str[size] = 0;
	return (str);
}

