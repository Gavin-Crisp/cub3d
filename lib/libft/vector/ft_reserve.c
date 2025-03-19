/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:21 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 14:20:11 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	next_highest_p2(size_t n)
{
	size_t	power;

	power = 1;
	while (power <= n)
		power *= 2;
	return (power);
}

void	ft_vecreserve(t_vector *vec, size_t num_elems)
{
	size_t	old_size;

	if (vec->length + num_elems <= vec->_capacity)
		return ;
	old_size = vec->_capacity * vec->_elem_size;
	vec->_capacity = next_highest_p2(vec->_capacity + num_elems);
	vec->data = ft_simple_realloc(vec->data, old_size,
			vec->_capacity * vec->_elem_size);
}
