/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoncho <yoncho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 22:41:50 by yoncho            #+#    #+#             */
/*   Updated: 2021/01/27 20:10:08 by yoncho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					find_enter(char *backup)
{
	int				i;

	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int					cutting_line(char **backup, char **line, int cut_idx)
{
	char			*tmp;
	int				len;

	(*backup)[cut_idx] = '\0';
	*line = ft_strdup(*backup);
	len = ft_strlen(*backup + cut_idx + 1);
	if (len == 0)
	{
		free(*backup);
		*backup = 0;
		return (1);
	}
	tmp = ft_strdup(*backup + cut_idx + 1);
	free(*backup);
	*backup = tmp;
	return (1);
}

int					end_line(char **backup, char **line, int r_size)
{
	int				enter_i;

	if (r_size < 0)
		return (-1);
	if (*backup && (enter_i = find_enter(*backup)) >= 0)
		return (cutting_line(backup, line, enter_i));
	else if (*backup)
	{
		*line = *backup;
		*backup = 0;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int					get_next_line(int fd, char **line)
{
	static char		*backup[OPEN_MAX];
	char			buff[BUFFER_SIZE + 1];
	int				r_size;
	int				find_enter_i;

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	while ((r_size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r_size] = '\0';
		backup[fd] = ft_strjoin(backup[fd], buff);
		if ((find_enter_i = find_enter(backup[fd])) >= 0)
			return (cutting_line(&backup[fd], line, find_enter_i));
	}
	return (end_line(&backup[fd], line, r_size));
}
