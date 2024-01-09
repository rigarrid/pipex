/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:57:34 by rigarrid          #+#    #+#             */
/*   Updated: 2024/01/09 12:53:47 by rigarrid         ###   ########.fr       */
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

static void	ft_matrixerror(char **matrix, int c)
{
	if (c == 1)
		ft_printf("No such file or directory: %s\n", matrix[0]);
	freematrix(matrix);
}

t_references	ft_cmdmanager(char **argv, char **envp)
{
	t_references	data;

	data.cmd1 = ft_split(argv[2], ' ');
	data.cmd2 = ft_split(argv[3], ' ');
	if (data.cmd1[0][0] == '/' && access(data.cmd1[0], F_OK) == 0)
		data.path1 = data.cmd1[0];
	else if (data.cmd1[0][0] == '/' && access(data.cmd1[0], F_OK) != 0)
		ft_matrixerror(data.cmd1, 1);
	else
		data.path1 = ft_find_path(envp, data.cmd1[0]);
	if (data.cmd2[0][0] == '/' && access(data.cmd2[0], F_OK) == 0)
		data.path2 = data.cmd2[0];
	else if (data.cmd2[0][0] == '/' && access(data.cmd2[0], F_OK) != 0)
		ft_matrixerror(data.cmd2, 1);
	else
		data.path2 = ft_find_path(envp, data.cmd2[0]);
	if (data.path1 == 0)
		ft_printf("Command not found: %s\n", data.cmd1[0]);
	if (data.path2 == 0)
		ft_printf("Command not found: %s\n", data.cmd2[0]);
	return (data);
}
