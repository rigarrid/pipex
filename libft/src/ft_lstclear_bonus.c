/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rigarrid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 15:54:01 by rigarrid          #+#    #+#             */
/*   Updated: 2022/07/11 15:54:04 by rigarrid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		aux = ((*lst)->next);
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
}
