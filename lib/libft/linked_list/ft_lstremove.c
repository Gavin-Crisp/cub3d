/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 08:22:16 by gcrisp            #+#    #+#             */
/*   Updated: 2024/09/17 14:25:43 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstremove(t_list **headptr, size_t index, void (*f_free)(void *))
{
	t_list	*prev;
	t_list	*elem;

	if (!headptr || !*headptr)
		return ;
	elem = ft_lstindex(*headptr, index);
	if (index)
	{
		prev = ft_lstindex(*headptr, index - 1);
		prev->next = elem->next;
	}
	else
		*headptr = elem->next;
	f_free(elem->data);
	free(elem);
}
