/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_front.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:11:32 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/10 16:16:46 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstadd_front(t_dllist **headptr, t_dllist *new)
{
	t_dllist	*last;

	last = ft_dllstlast(new);
	(*headptr)->prev = last;
	last->next = *headptr;
	*headptr = ft_dllstfirst(new);
}
