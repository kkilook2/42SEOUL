/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 21:22:23 by yoncho            #+#    #+#             */
/*   Updated: 2021/02/06 20:47:57 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H 
# define FT_PRINTF_H
#	include <stdarg.h>
#	include <stdio.h>
# include "./libft/libft.h"
# include <stdbool.h>
# include <stdlib.h>

typedef struct _Flags {
	int		minus; // - 는 왼쪽 정렬
	int		zero; //0으로 채운다
	int		dot;   
	int		width; //폭
	int		prec;  //정밀도
	int		star;
}			flags;

#endif