/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_elem.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 09:29:36 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/19 09:36:14 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstremove_elem(t_dllist **elemptr, void (*fr)(void *))
{
	t_dllist	*elem;

	elem = *elemptr;
	if (elem->next)
		*elemptr = elem->next;
	else if (elem->prev)
		*elemptr = elem->prev;
	else
		*elemptr = 0;
	if (elem->next)
		elem->next->prev = elem->prev;
	if (elem->prev)
		elem->prev->next = elem->next;
	fr(elem->data);
	free(elem);
}
