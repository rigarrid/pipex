/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 12:46:30 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/27 15:46:34 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*result;
	unsigned int	c;
	int				max;
	int				l;

	if (!s)
		return (NULL);
	l = ft_strlen(s);
	if (start > (unsigned int)l)
		return (ft_strdup(""));
	if (len > l - start)
		max = l - start;
	else
		max = len;
	result = malloc(sizeof(char) * max + 1);
	if (!result)
		return (NULL);
	c = 0;
	while (c < (unsigned int)max)
	{
		result[c] = s[c + start];
		c++;
	}
	result[c] = 0;
	return (result);
}
