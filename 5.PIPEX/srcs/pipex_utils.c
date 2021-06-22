/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 19:37:07 by yoncho            #+#    #+#             */
/*   Updated: 2021/06/19 14:51:47 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void		redirect_in(const char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
}

void		redirect_out(const char *file)
{
	int		fd;

	fd = open(file, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror(file);
		exit(1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
}

void		connect_pipe(int pipefd[2], int io)
{
	dup2(pipefd[io], io);
	close(pipefd[0]);
	close(pipefd[1]);
}

static void	cmd_init(const char *in_cmd, t_cmd *cmds)
{
	char	**cmd;

	cmd = ft_split(in_cmd, ' ');
	cmds->cmd[0] = ft_strjoin("/bin/", cmd[0]);
	cmds->cmd[1] = ft_strjoin("/usr/local/bin/", cmd[0]);
	cmds->cmd[2] = ft_strjoin("/usr/bin/", cmd[0]);
	cmds->cmd[3] = ft_strjoin("/usr/sbin/", cmd[0]);
	cmds->cmd[4] = ft_strjoin("/sbin/", cmd[0]);
	cmds->argv = (char *const *)cmd;
}

void		run_cmd(const char *cmd)
{
	int		i;
	t_cmd	cmd_arg;

	i = 0;
	cmd_init(cmd, &cmd_arg);
	while (i < 5)
		execve(cmd_arg.cmd[i++], cmd_arg.argv, NULL);
	perror(cmd_arg.argv[0]);
}
