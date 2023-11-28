/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:38:02 by rigarrid          #+#    #+#             */
/*   Updated: 2023/11/28 15:26:00 by rigarrid         ###   ########.fr       */
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
    char    *path1;
    char    *path2;
    char    **cmd1;
    char    **cmd2;
}   t_references;
#endif