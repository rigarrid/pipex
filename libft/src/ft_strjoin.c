/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <rigarrid@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:26:49 by rigarrid          #+#    #+#             */
/*   Updated: 2023/12/13 15:56:30 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*result;
	int		c;
	int		c2;

	if (!s1)
		return (NULL);
	result = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (result == NULL)
		return (NULL);
	c = -1;
	c2 = 0;
	while (s1[++c])
	{
		result[c2] = s1[c];
		c2++;
	}
	c = -1;
	while (s2[++c])
	{
		result[c2] = s2[c];
		c2++;
	}
	result[c2] = 0;
	return (result);
}
