/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 11:31:18 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/06 13:31:48 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include "../includes/libft.h"
#include <stdlib.h>

static size_t	word_counter(char const *s, char c)
{
	size_t	word;
	size_t	con;

	word = 0;
	con = 0;
	while (s && s[con])
	{
		if (s[con] != c)
		{
			word++;
			while (s[con] != c && s[con])
				con++;
		}
		else
			con++;
	}
	return (word);
}

static size_t	lenght_counter(char const *s, char c, size_t con)
{
	size_t	lenght;

	lenght = 0;
	while (s[con] != c && s[con])
	{
		lenght++;
		con++;
	}
	return (lenght);
}

static void	*ft_free(char **result, size_t icon)
{
	while (icon > 0)
	{
		free(result[--icon]);
	}
	free(result);
	result = NULL;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	index;
	size_t	icon;
	size_t	con;
	size_t	len;

	index = word_counter(s, c);
	con = 0;
	icon = -1;
	result = (char **)ft_calloc(sizeof(char *) * (index + 1), 1);
	if (result == NULL)
		return (NULL);
	while (++icon < index)
	{
		while (s[con] == c)
			con++;
		len = lenght_counter(s, c, con);
		result[icon] = ft_substr(s, con, len);
		if (result[icon] == NULL)
		{
			return (ft_free(result, icon));
		}
		con += len;
	}
	return (result);
}
