/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 12:08:09 by gcrisp            #+#    #+#             */
/*   Updated: 2024/09/03 12:13:40 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **headptr, size_t index)
{
	t_list	*prev;
	t_list	*elem;

	if (index == 0)
	{
		elem = *headptr;
		*headptr = elem->next;
	}
	else
	{
		prev = ft_lstindex(*headptr, index - 1);
		elem = prev->next;
		prev->next = elem->next;
	}
	elem->next = 0;
	return (elem);
}
