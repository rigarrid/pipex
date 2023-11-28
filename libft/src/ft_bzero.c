/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 16:06:54 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/27 15:47:10 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	con;
	char	*aux;

	con = 0;
	aux = s;
	while (con < n)
	{
		aux[con] = 0;
		con++;
	}
}
