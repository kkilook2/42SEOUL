/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 14:51:37 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/07 16:11:18 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int   check_format(char format)
{
  if ((ft_isdigit(format)) && (ft_strchr("csdixX%up", format)) 
      && (ft_strchr("-0.*", format)))
			return (1);
  return (0);
}
