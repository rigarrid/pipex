/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 12:32:07 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 09:38:12 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		int c = the ascii value of the character we want to print.
 * OUT:
 * 		int size = the number of characters we printed. 
 */

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}
