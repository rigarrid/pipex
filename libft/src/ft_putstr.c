/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:10:14 by rigarrid          #+#    #+#             */
/*   Updated: 2022/11/21 09:43:20 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

/*
 * IN:
 * 		char *str = the string we want to print.
 * OUT:
 * 		int size = the number of characters we printed.
 */

int	ft_putstr(char *str)
{
	int	size;

	size = 0;
	if (str == NULL)
		size = ft_putstr("(null)");
	else
		while (str[size])
			write(1, &str[size++], 1);
	return (size);
}
