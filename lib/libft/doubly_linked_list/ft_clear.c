/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 09:23:21 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:29:12 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dllstclear(t_dllist **headptr, void (*fr)(void *))
{
	if (*headptr)
	{
		ft_dllstclear(&(*headptr)->next, fr);
		fr((*headptr)->data);
		free(*headptr);
		*headptr = 0;
	}
}
