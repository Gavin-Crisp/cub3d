/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 10:24:36 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:30:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstmin(t_list *head, int (*cmp)(void *, void *))
{
	size_t	min_index;
	size_t	i;
	void	*min;

	min_index = 0;
	min = head->data;
	i = 0;
	while (head->next)
	{
		i++;
		head = head->next;
		if (cmp(min, head->data) > 0)
		{
			min = head->data;
			min_index = i;
		}
	}
	return (min_index);
}
