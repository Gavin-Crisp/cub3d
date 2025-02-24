/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   match.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 14:54:02 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/15 11:08:19 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_dllstmatch(t_dllist *find, t_dllist *in, int (*cmp)(void *, void *))
{
	while (find && in)
	{
		if (cmp(find->data, in->data))
			break ;
		find = find->next;
		in = in->next;
	}
	return (!find);
}
