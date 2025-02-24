/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_before.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 12:04:08 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/15 15:21:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstinsert_before(t_dllist *elem, t_dllist *new)
{
	t_dllist	*first;
	t_dllist	*last;

	if (!new)
		return ;
	if (!elem->prev)
		return (ft_dllstadd_front(&elem, new));
	first = ft_dllstfirst(new);
	last = ft_dllstlast(new);
	elem->prev->next = first;
	first->prev = elem->prev;
	elem->prev = last;
	last->next = elem;
}
