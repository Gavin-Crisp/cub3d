/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:09:40 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:29:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dllist	*ft_dllstfind(t_dllist *head, void *ref, int (*cmp)(void *, void *))
{
	while (!cmp(ref, head->data) && head)
		head = head->next;
	return (head);
}
