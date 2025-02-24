/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:33:50 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/10 13:04:42 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstis_sorted(t_list *head, int (*cmp)(void *, void *))
{
	if (!head)
		return (1);
	while (head->next)
	{
		if (cmp(head->data, head->next->data) > 0)
			return (0);
		head = head->next;
	}
	return (1);
}
