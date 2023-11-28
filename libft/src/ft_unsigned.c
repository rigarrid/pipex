/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 11:17:01 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 09:53:12 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		unsigned int nb = the value we want to print
 * OUT:
 * 		size = the number of characters the function printed
 */

int	ft_unsigned(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb > 9)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putnbr(nb % 10);
	}
	else
		size += ft_putchar(nb + 48);
	return (size);
}
