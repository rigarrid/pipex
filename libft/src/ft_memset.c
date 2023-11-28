/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 14:40:56 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/11 12:00:56 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	con;
	char	*aux;

	aux = str;
	con = 0;
	while (con < len)
	{
		aux[con] = c;
		con++;
	}
	return (aux);
}
