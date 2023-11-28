/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:48:45 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/27 12:53:28 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	c;

	c = 0;
	if (n == 0)
		return (0);
	while ((*((unsigned char *)s1 + c) == *((unsigned char *)s2 + c))
		&& c < n - 1)
		c++;
	return (*((unsigned char *)s1 + c) - *((unsigned char *)s2 + c));
}
