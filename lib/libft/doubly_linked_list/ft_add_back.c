/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_back.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:14:11 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/10 14:25:50 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstadd_back(t_dllist **headptr, t_dllist *new)
{
	t_dllist	*last;

	if (!*headptr)
		*headptr = new;
	else
	{
		last = ft_dllstlast(*headptr);
		new->prev = last;
		last->next = new;
	}
}
