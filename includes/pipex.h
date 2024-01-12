/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:38:02 by rigarrid          #+#    #+#             */
/*   Updated: 2024/01/12 17:29:09 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_references
{
	char	*path1;
	char	*path2;
	char	**cmd1;
	char	**cmd2;
	int		end[2];
	int		f[2];
	int		parent[2];
}	t_references;
t_references	ft_cmdmanager(char **argv, char **envp);
void			freematrix(char **str);
void			ft_freeall(t_references data);
char			*ft_find_path(char **paths, char *cmd);
#endif