/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 12:19:03 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 12:21:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecclear(t_vector *vec, void (*clear)(void *))
{
	size_t	i;

	i = 0;
	if (clear)
	{
		while (i < vec->length)
			clear(ft_vecindex(vec, i));
	}
	vec->length = 0;
}
