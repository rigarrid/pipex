/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 11:30:32 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/27 13:15:46 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <limits.h>

int	ft_atoi(const char *a)
{
	unsigned long	num;
	int				con;
	int				aux;

	num = 0;
	con = 0;
	aux = 1;
	while (a[con] == 32 || (a[con] <= 13 && a[con] > 0))
		con++;
	if (a[con] == '-')
		aux *= -1;
	if (a[con] == '+' || a[con] == '-')
		con++;
	while (a[con] >= '0' && a[con] <= '9')
	{
		num = a[con] - 48 + (num * 10);
		con++;
	}
	if (num > 9223372036854775807 && aux == 1)
		return (-1);
	else if (num - 1 > 9223372036854775807 && aux == -1)
		return (0);
	return (num * aux);
}
