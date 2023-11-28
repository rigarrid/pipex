/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:55:45 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/11 15:55:47 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cont;

	if (lst == NULL)
		return (0);
	cont = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		cont++;
	}
	return (cont);
}
