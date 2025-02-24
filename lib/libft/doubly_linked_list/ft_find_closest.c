/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_closest.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:22:59 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:23:08 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dllist	*ft_dllstfind_closest(
				t_dllist *head,
				void *ref,
				int (*cmp)(void *, void *)
			)
{
	t_dllist	*closest;
	int			closest_res;
	int			res;

	if (!head)
		return (0);
	closest = head;
	closest_res = cmp(head->data, ref);
	while (head->next && closest_res != 0)
	{
		head = head->next;
		res = cmp(head->data, ref);
		if (res < 0)
			res = -res;
		if (res >= closest_res)
			continue ;
		closest_res = res;
		closest = head;
	}
	return (closest);
}
