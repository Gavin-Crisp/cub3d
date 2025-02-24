/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:29:42 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:30:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstmax(t_list *head, int (*cmp)(void *, void *))
{
	size_t	max_index;
	size_t	i;
	void	*max;

	max_index = 0;
	max = head->data;
	i = 0;
	while (head)
	{
		i++;
		head = head->next;
		if (cmp(max, head->data) < 0)
		{
			max = head->data;
			max_index = i;
		}
	}
	return (max_index);
}
