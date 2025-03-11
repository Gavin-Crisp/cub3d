/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_elems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:44 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:36:57 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vecinsert_elems(
	t_vector *vec,
	void *elems,
	size_t num_elems,
	size_t index)
{
	void	*mem_loc;

	if (index > vec->length)
		return (0);
	ft_vecreserve(vec, num_elems);
	mem_loc = ft_vecindex(vec, index);
	ft_memmove(mem_loc + num_elems * vec->_elem_size, mem_loc,
		(vec->length - index) * vec->_elem_size);
	ft_memcpy(mem_loc, elems, num_elems * vec->_elem_size);
	vec->length += num_elems;
	return (1);
}
