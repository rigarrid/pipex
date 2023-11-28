/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 15:57:54 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/28 11:30:53 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "../includes/libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t nb)
{
	size_t	dlen;
	size_t	d;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = ft_strlen((char *)src);
	d = 0;
	if (nb == 0)
		return (slen);
	if (dlen > nb)
		return (slen + nb);
	while (((unsigned char *) src)[d] && dlen < (nb - 1))
	{
		dest[dlen] = ((unsigned char *) src)[d];
		dlen++;
		d++;
	}
	if (d < nb)
		dest[dlen] = 0;
	return ((dlen - d) + slen);
}
