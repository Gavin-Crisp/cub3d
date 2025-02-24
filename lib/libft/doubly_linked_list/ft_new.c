/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:05:58 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:39:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dllist	*ft_dllstnew(void *data)
{
	t_dllist	*new;

	new = malloc(sizeof(t_dllist));
	new->prev = 0;
	new->next = 0;
	new->data = data;
	return (new);
}
