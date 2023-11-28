/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 12:05:08 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 10:57:44 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		long int nb = the value we want to print
 * OUT:
 * 		size = the number of characters that we printed
 */

int	ft_putnbr(long int nb)
{
	int	size;

	size = 0;
	if (nb == -2147483648)
	{
		size += ft_putchar('-');
		size += ft_putchar('2');
		size += ft_putnbr(147483648);
	}
	else if (nb < 0)
	{
		size += ft_putchar('-');
		nb *= -1;
		size += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		size += ft_putnbr(nb / 10);
		size += ft_putnbr(nb % 10);
	}
	else
		size += ft_putchar(nb + 48);
	return (size);
}
