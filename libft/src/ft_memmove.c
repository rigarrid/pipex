/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:23:22 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/17 15:47:38 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t		con;
	const char	*src2;
	char		*dst2;

	con = 0;
	src2 = src;
	dst2 = dst;
	if (dst == src)
		return (dst);
	if (dst < src)
	{
		while (con < n)
		{
			*(dst2 + con) = *(src2 + con);
			con++;
		}
	}
	if (dst > src)
	{
		while (n--)
			*(dst2 + n) = *(src2 + n);
	}
	return (dst);
}
