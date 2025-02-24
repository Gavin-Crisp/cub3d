/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:28:56 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/10 13:05:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dllstis_sorted(t_dllist *head, int (*cmp)(void *, void *))
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
