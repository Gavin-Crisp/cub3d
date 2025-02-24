/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind_closest.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:26:04 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:26:06 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind_closest(t_list *head, void *ref, int (*cmp)(void *, void *))
{
	t_list	*closest;
	int		res;
	int		closest_res;

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
