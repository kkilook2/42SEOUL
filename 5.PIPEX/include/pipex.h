/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:01:22 by yoncho            #+#    #+#             */
/*   Updated: 2021/06/19 14:50:51 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"

# define F_1	1
# define F_2	4
# define C_1	2
# define C_2	3

typedef struct		s_cmd
{
	const char		*cmd[5];
	char *const		*argv;
}					t_cmd;

void				redirect_in(const char *file);
void				redirect_out(const char *file);
void				connect_pipe(int pipefd[2], int io);
void				run_cmd(const char *cmd);

#endif
