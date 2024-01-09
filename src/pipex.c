/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:36 by rigarrid          #+#    #+#             */
/*   Updated: 2024/01/09 12:48:07 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*void	leaks(void)
{
	system("/usr/bin/leaks -q pipex");
}*/

char	*ft_find_path(char **paths, char *cmd)
{
	int		c;
	char	**semi_env;
	char	*semipath;
	char	*fullpath;

	c = 0;
	while (paths[c] != NULL && (ft_strnstr(paths[c], "PATH", 4)) == 0)
		c++;
	if (paths[c] == NULL)
		return ("");
	semi_env = ft_split(paths[c] + 5, ':');
	c = -1;
	while (semi_env[++c])
	{
		semipath = ft_strjoin(semi_env[c], "/");
		fullpath = ft_strjoin(semipath, cmd);
		free(semipath);
		if (access(fullpath, F_OK) == 0)
			return ((freematrix(semi_env)), fullpath);
		free(fullpath);
	}
	freematrix(semi_env);
	return (0);
}

int	ft_child(t_references *data, char **envp, int fd1)
{
	if (dup2(fd1, STDIN_FILENO) < 0 || dup2(data->end[1], STDOUT_FILENO) < 0)
		return (EXIT_FAILURE);
	close(data->end[0]);
	close(fd1);
	execve(data->path1, data->cmd1, envp);
	exit(EXIT_FAILURE);
}

int	ft_parent(t_references *data, char **envp, int fd2)
{
	if (dup2(fd2, STDOUT_FILENO) < 0 || dup2(data->end[0], STDIN_FILENO) < 0)
		return (EXIT_FAILURE);
	close(data->end[1]);
	close(fd2);
	execve(data->path2, data->cmd2, envp);
	exit(EXIT_FAILURE);
}

int	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int				status;
	t_references	data;

	data = ft_cmdmanager(argv, envp);
	pipe(data.end);
	data.parent = fork();
	if (data.parent < 0)
		return (EXIT_FAILURE);
	if (data.parent == 0)
		ft_child(&data, envp, fd1);
	waitpid(-1, &status, 0);
	if (data.parent > 0)
		ft_parent(&data, envp, fd2);
	return (0);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];

	if (argc != 5)
		return (ft_printf("Wrong number of arguments."));
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd[0] < 0 || fd[1] < 0)
	{
		if (fd[0] < 0)
			ft_printf("Error with the infile\n");
		if (fd[1] < 0)
			ft_printf("Error with the outfile\n");
		return (-1);
	}
	pipex(fd[0], fd[1], argv, envp);
	return (0);
}
