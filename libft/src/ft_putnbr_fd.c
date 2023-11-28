/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 13:37:25 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/06 14:03:02 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <unistd.h>

static void	core(int nb, int fd)
{
	if (nb == -2147483648)
	{
		ft_putchar_fd('-', fd);
		ft_putchar_fd('2', fd);
		core(147483648, fd);
	}
	else if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		core(nb *= -1, fd);
	}
	else if (nb > 9)
	{
		core(nb / 10, fd);
		core(nb % 10, fd);
	}
	else
		ft_putchar_fd(nb + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	core(n, fd);
}
