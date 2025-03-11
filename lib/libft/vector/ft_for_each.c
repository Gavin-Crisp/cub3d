/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_for_each.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:30:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecfor_each(t_vector *vec, void (*action)(void *, size_t))
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		action(ft_vecindex(vec, i), i);
		i++;
	}
}
