/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 11:46:30 by gcrisp            #+#    #+#             */
/*   Updated: 2024/10/15 13:06:24 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsplit(t_list **headptr, int (*pred)(void *),
			void (*f_free)(void *))
{
	t_list	*out;
	t_list	*current;

	out = 0;
	while (*headptr)
	{
		while (*headptr && pred((*headptr)->data))
			ft_lstremove(headptr, 0, f_free);
		current = *headptr;
		while (current->next && !pred(current->next->data))
			current = current->next;
		ft_lstadd_back(&out, ft_lstnew(*headptr));
		*headptr = current->next;
		current->next = 0;
		if (*headptr)
			ft_lstremove(headptr, 0, f_free);
	}
	return (out);
}
