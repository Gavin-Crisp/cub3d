/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:14 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:36:49 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vecremove(t_vector *vec, size_t index)
{
	void	*elem;
	void	*mem_loc;

	if (index >= vec->length)
		return (0);
	elem = malloc(vec->_elem_size);
	mem_loc = ft_vecindex(vec, index);
	ft_memcpy(elem, mem_loc, vec->_elem_size);
	ft_memmove(mem_loc, mem_loc + vec->_elem_size,
		(vec->length - index - 1) * vec->_elem_size);
	vec->length--;
	return (elem);
}
