/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:43:32 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/15 15:21:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dllstcmp(t_dllist *l1, t_dllist *l2, int (*cmp)(void *, void *))
{
	int	c;

	while (l1 && l2)
	{
		c = cmp(l1->data, l2->data);
		if (c)
			return (c);
		l1 = l1->next;
		l2 = l2->next;
	}
	if (!l1 && l2)
		return (-1);
	if (!l2 && l1)
		return (1);
	return (0);
}
