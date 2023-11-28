/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:50:55 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/17 16:12:15 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	c;

	c = 0;
	if (size == 0)
	{
		return (ft_strlen(src));
	}
	while (src[c] != 0 && c < size - 1)
	{
		dest[c] = src[c];
		c++;
	}
	dest[c] = 0;
	return (ft_strlen(src));
}
