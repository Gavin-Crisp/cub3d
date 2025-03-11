/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:30:51 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:30:52 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecmap(t_vector *vec, void *(*map)(void *, size_t))
{
	t_vector	*out;
	size_t		i;
	void		*new_elem;

	out = ft_vecnew_with_capacity(vec->length, vec->_elem_size);
	out->length = vec->length;
	i = 0;
	while (i < vec->length)
	{
		new_elem = map(ft_vecindex(vec, i), i);
		ft_memcpy(ft_vecindex(out, i++), new_elem, out->_elem_size);
		free(new_elem);
	}
	return (out);
}
