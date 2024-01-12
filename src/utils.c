/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:57:34 by rigarrid          #+#    #+#             */
/*   Updated: 2024/01/12 17:28:54 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	freematrix(char **str)
{
	int		c;

	c = 0;
	while (str[c] != NULL)
		free(str[c++]);
	free(str);
}

void	ft_freeall(t_references data)
{
	if (data.f[0] == 1)
		free(data.path1);
	if (data.f[1] == 1)
		free(data.path2);
	freematrix(data.cmd1);
	freematrix(data.cmd2);
}

static int	ft_routecmp(char *s1)
{
	if (ft_strncmp(s1, "./", 2) == 0)
		return (0);
	if (ft_strncmp(s1, "../", 3) == 0)
		return (0);
	if (ft_strncmp(s1, "/", 1) == 0)
		return (0);
	return (1);
}

t_references	ft_cmdmanager(char **argv, char **envp)
{
	t_references	data;

	data.f[0] = 0;
	data.f[1] = 0;
	data.cmd1 = ft_split(argv[2], ' ');
	data.cmd2 = ft_split(argv[3], ' ');
	if (ft_routecmp(data.cmd1[0]) == 0)
		data.path1 = data.cmd1[0];
	else
	{
		data.path1 = ft_find_path(envp, data.cmd1[0]);
		data.f[0] = 1;
	}
	if (ft_routecmp(data.cmd2[0]) == 0)
		data.path2 = data.cmd2[0];
	else
	{
		data.path2 = ft_find_path(envp, data.cmd2[0]);
		data.f[1] = 1;
	}
	return (data);
}
