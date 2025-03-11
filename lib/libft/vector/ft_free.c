/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:37 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/13 13:30:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecfree(t_vector **pvec, void (*clear)(void *))
{
	size_t	i;

	if (clear)
	{
		i = 0;
		while (i < (*pvec)->length)
			clear(ft_vecindex(*pvec, i++));
	}
	free((*pvec)->data);
	free(*pvec);
	*pvec = 0;
}
