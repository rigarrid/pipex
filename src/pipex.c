/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:36 by rigarrid          #+#    #+#             */
/*   Updated: 2023/11/28 16:32:08 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_find_path(char **paths, char *cmd)
{
	int 	c;
	char	**semi_path;
	char	*fullcmd;

	c = 0;
    while ((ft_strnstr(paths[c], "PATH", 4)) == 0)
        c++;
    semi_path = ft_split(paths[c] + 5, ':');
	c = -1;
	while (semi_path[++c])
    {
		fullcmd = ft_strjoin(semi_path[c], "/");
		fullcmd = ft_strjoin(fullcmd, cmd);
		if (access(fullcmd, F_OK) == 0)
			return (fullcmd);
	}
    return (0);
}

int	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	int		status;
    int		parent;
	t_references data;

	data.cmd1 = ft_split(argv[2], ' ');
	data.path1 = ft_find_path(envp, data.cmd1[0]);
	data.cmd2 = ft_split(argv[3], ' ');
	data.path2 = ft_find_path(envp, data.cmd2[0]);
	if (data.path1 == 0 || data.path2 == 0)
	{
		ft_printf("ERROR: one of the commands doesnt exist");
		return (-1);
	}
	pipe(end);
    parent = fork();
	if (parent < 0)
		return (EXIT_FAILURE);
    if (!parent)
    {
		if (dup2(fd1, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
			return (EXIT_FAILURE);
		close(end[0]);
		close(fd1);
		execve(data.path1, data.cmd1, envp);
		exit(EXIT_FAILURE);
	}
    else
	{// Padre
	
		waitpid(-1, &status, 0);
		if (dup2(fd2, STDOUT_FILENO) < 0 || dup2(end[0], STDIN_FILENO) < 0)
			return (EXIT_FAILURE);
		close(end[1]);
		close(fd2);
		execve(data.path2, data.cmd2, envp);
		exit(EXIT_FAILURE);
	}
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	int	fd[2];
    if (argc != 5)
		return (ft_printf("Wrong number of arguments.\ninfile cmd1 cmd2 outfile\n"));
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
		return (-1);
	pipex(fd[0], fd[1], argv, envp);
	system("leaks pipex");
	return (0);
}
