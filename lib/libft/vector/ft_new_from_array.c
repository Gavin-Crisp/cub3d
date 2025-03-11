/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_from_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:33:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecnew_from_array(
	void *elements,
	size_t length,
	size_t elem_size)
{
	t_vector	*out;

	out = ft_vecnew_with_capacity(length, elem_size);
	out->length = length;
	ft_memcpy(out->data, elements, length * elem_size);
	return (out);
}
