/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:37:23 by yoncho            #+#    #+#             */
/*   Updated: 2021/06/19 14:48:10 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char const *argv[])
{
	int		p_fd[2];
	int		status;
	pid_t	pid;

	if (argc != 5)
		return (0);
	pipe(p_fd);
	pid = fork();
	if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) == 0)
			exit(1);
		redirect_out(argv[F_2]);
		connect_pipe(p_fd, STDIN_FILENO);
		run_cmd(argv[C_2]);
	}
	else if (pid == 0)
	{
		redirect_in(argv[F_1]);
		connect_pipe(p_fd, STDOUT_FILENO);
		run_cmd(argv[C_1]);
	}
	return (0);
}
