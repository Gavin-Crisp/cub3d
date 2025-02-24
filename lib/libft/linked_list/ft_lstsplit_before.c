/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsplit_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 13:02:11 by gcrisp            #+#    #+#             */
/*   Updated: 2024/08/30 13:03:28 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstsplit_before(t_list **headptr, int (*pred)(void *))
{
	t_list	*out;
	t_list	*current;

	out = 0;
	while (*headptr)
	{
		current = *headptr;
		while (current->next && !pred(current->next->data))
			current = current->next;
		ft_lstadd_back(&out, ft_lstnew(*headptr));
		*headptr = current->next;
		current->next = 0;
	}
	return (out);
}
