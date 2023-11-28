/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:53:46 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/11 15:53:48 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*node;

	if (new == NULL)
		return ;
	node = *lst;
	*lst = new;
	new->next = node;
}
