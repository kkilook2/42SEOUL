/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/01 20:14:17 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/02 00:08:51 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *s;

	if (!(s = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	s->content = content;
	s->next = NULL;
	return (s);
}
