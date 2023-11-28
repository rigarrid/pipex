/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 18:22:19 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/06 12:52:14 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	con;

	if (!s)
		return (NULL);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	con = 0;
	while (str[con])
	{
		str[con] = (*f)(con, str[con]);
		con++;
	}
	return (str);
}
