/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:59:45 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/06 11:47:31 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	con;

	con = 0;
	if (!s || !f)
		return ;
	while (s[con])
	{
		(*f)(con, s + con);
		con++;
	}
}
