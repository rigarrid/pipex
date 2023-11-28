/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:57:07 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/06 12:57:42 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int		size;

	size = 0;
	if (!s1)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size && ft_strchr(set, s1[size]))
		size--;
	aux = ft_substr(s1, 0, size + 1);
	return (aux);
}
