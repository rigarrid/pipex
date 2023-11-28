/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:19:34 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/27 17:49:03 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*result;
	size_t	sum;

	sum = count * size;
	if (sum < count && sum < size)
		return (NULL);
	result = malloc(sum);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, sum);
	return (result);
}
