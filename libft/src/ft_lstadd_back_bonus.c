/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:53:27 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/27 13:16:40 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!lst)
		return ;
	if (*lst)
	{
		tmp = *lst;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}
