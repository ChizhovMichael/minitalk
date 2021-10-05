/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgildero <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 21:59:04 by tgildero          #+#    #+#             */
/*   Updated: 2021/09/29 22:48:55 by tgildero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*nextel;

	elem = *lst;
	while (elem)
	{
		nextel = elem->next;
		ft_lstdelone(elem, del);
		elem = nextel;
	}
	*lst = NULL;
}
