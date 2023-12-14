/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:37:36 by rigarrid          #+#    #+#             */
/*   Updated: 2023/12/14 17:17:24 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	leaks(void)
{
	system("leaks -q pipex");
}

void	freematrix(char **str)
{
	int c;

	c = 0;
	while (str[c] != NULL)
		free(str[c++]);
	free(str);
}
char	*ft_find_path(char **paths, char *cmd)
{
	int 	c;
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

int	pipex(int fd1, int fd2, char **argv, char **envp)
{
	int		end[2];
	int		status;
    int		parent;
	t_references data;

	
	data = ft_cmdmanager(argv, envp);
	//system("/usr/bin/leaks -q pipex");
	pipe(end);
    parent = fork();
	if (parent < 0)
		return (EXIT_FAILURE);
    if (parent == 0)//sirve para el primer y ultimo comando
    {
		if (dup2(fd1, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
			return (EXIT_FAILURE);
		close(end[0]);
		close(fd1);
		execve(data.path1, data.cmd1, envp);
		exit(EXIT_FAILURE);
	}
	waitpid(-1, &status, 0);
    if (parent > 0)
	{// Padre
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
	{
		if (fd[0] < 0)
			ft_printf("Error with the infile\n");
		if (fd[1] < 0)
			ft_printf("Error with the outfile\n");
		return (-1);
	}
	pipex(fd[0], fd[1], argv, envp);
	atexit(leaks);
	return (0);
}
