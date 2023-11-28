/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:04:19 by rigarrid          #+#    #+#             */
/*   Updated: 2022/06/30 18:11:46 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"
#include <stdio.h>
#include <stdlib.h>

static size_t	len_counter(long int n)
{
	size_t	con;

	con = 0;
	if (n < 0)
	{
		n *= -1;
		con++;
	}
	while (n >= 10)
	{
		con++;
		n = n / 10;
	}
	return (con + 1);
}

static char	pull_number(long int n)
{
	while (n > 9)
		n = n % 10;
	return (n + 48);
}

static void	rev_array(char *result)
{
	size_t	con;
	size_t	con2;
	char	backup;

	con = 0;
	con2 = ft_strlen(result) - 1;
	if (result[con] == '-')
		con++;
	while (con < con2)
	{
		backup = result[con];
		result[con] = result[con2];
		result[con2] = backup;
		con++;
		con2--;
	}
}

char	*ft_itoa(int n)
{
	long int	nb;
	size_t		len[2];
	char		*result;

	len[0] = len_counter(n);
	nb = n;
	len[1] = 0;
	result = (char *)malloc(sizeof(char) * len[0] + 1);
	if (result == NULL)
		return (NULL);
	if (nb < 0)
	{
		nb *= -1;
		result[len[1]] = '-';
		len[1]++;
	}
	while (nb > 9 || len[1] < len[0])
	{
		result[len[1]] = pull_number(nb);
		nb = nb / 10;
		len[1]++;
	}
	result[len[0]] = 0;
	rev_array(result);
	return (result);
}
