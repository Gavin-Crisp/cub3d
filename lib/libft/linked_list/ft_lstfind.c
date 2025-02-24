/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:51:31 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:41:04 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *head, void *ref, int (*cmp)(void *, void *))
{
	while (head)
	{
		if (!cmp(ref, head->data))
			return (head);
		head = head->next;
	}
	return (0);
}
