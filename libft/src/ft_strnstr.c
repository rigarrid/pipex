/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:29:11 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/27 16:37:22 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	c1;
	int		c2;

	c1 = 0;
	if (*s2 == 0)
		return ((char *) s1);
	while (s1[c1] && c1 < len)
	{
		if (s1[c1] == s2[0])
		{
			c2 = 0;
			while (s1[c1 + c2] && s2[c2] && c1 + c2 < len
				&& s1[c1 + c2] == s2[c2])
				c2++;
			if (s2[c2] == 0)
				return ((char *)s1 + c1);
		}
		c1++;
	}
	return (0);
}
