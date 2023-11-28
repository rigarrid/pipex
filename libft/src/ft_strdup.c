/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:08:18 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/27 16:24:56 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*result;

	result = malloc (sizeof (*result) * (ft_strlen(s1) + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s1, (ft_strlen(s1) + 1));
	return (result);
}
