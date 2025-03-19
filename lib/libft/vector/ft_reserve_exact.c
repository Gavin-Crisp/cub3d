/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reserve_exact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 14:00:53 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 14:21:53 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecreserve_exact(t_vector *vec, size_t num_elems)
{
	size_t	old_size;

	if (vec->length + num_elems <= vec->_capacity)
		return ;
	old_size = vec->_capacity * vec->_elem_size;
	vec->_capacity = num_elems;
	vec->data = ft_simple_realloc(vec->data, old_size,
			vec->_capacity * vec->_elem_size);
}
