/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 02:15:17 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/02 03:35:47 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *tmp;
	t_list *ret;

	if (!lst)
		return (0);
	if (!(ret = ft_lstnew((*f)(lst->content))))
		return (0);
	tmp = ret;
	lst = lst->next;
	while (lst)
	{
		if (!(tmp->next = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&ret, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ret);
}
