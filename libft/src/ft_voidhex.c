/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 09:39:07 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 10:53:29 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		void *pointer = the pointer we want to print
 * OUT:
 * 		int size = the number of characters we printed
 */

int	ft_voidhex(void *pointer)
{
	int	size;

	size = write(1, "0x", 2);
	size += ft_hex((unsigned long )pointer, 'x');
	return (size);
}
