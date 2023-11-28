/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 10:51:23 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/28 12:05:13 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while ((s1[c] == s2[c]) && (c < n - 1) && s1[c])
		c++;
	return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
}
