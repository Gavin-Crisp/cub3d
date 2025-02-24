/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_after.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:19:44 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/11 15:31:16 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstinsert_after(t_dllist *elem, t_dllist *new)
{
	t_dllist	*first;
	t_dllist	*last;

	if (!new)
		return ;
	if (!elem->next)
		return (ft_dllstadd_back(&elem, new));
	first = ft_dllstfirst(new);
	last = ft_dllstlast(new);
	elem->next->prev = last;
	last->next = elem->next;
	elem->next = first;
	first->prev = elem;
}
