/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:41:52 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 10:53:38 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		unsigned lon int num = the value that we want to print in hexadecimal
 * 		char f = the character we use to know if we want upper case or lower case
 * OUT:
 * 		int size = the number of characters the function printed
 */

int	ft_hex(unsigned long int num, char f)
{
	int	size;

	size = 0;
	if (num >= 16)
	{
		size += ft_hex(num / 16, f);
		size += ft_hex(num % 16, f);
	}
	else
	{
		if (num <= 9)
			size += ft_putchar(num + '0');
		else
		{
			if (f == 'X')
				size += ft_putchar(num - 10 + 'A');
			if (f == 'x')
				size += ft_putchar(num - 10 + 'a');
		}
	}
	return (size);
}
