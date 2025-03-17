/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:04 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 12:09:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vecpop(t_vector *vec)
{
	void	*elem;

	if (vec->length == 0)
		return (0);
	elem = malloc(vec->_elem_size);
	ft_memcpy(elem, ft_vecindex(vec, vec->length - 1), vec->_elem_size);
	vec->length--;
	return (elem);
}
