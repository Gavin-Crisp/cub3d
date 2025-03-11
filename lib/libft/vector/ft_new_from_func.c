/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_from_func.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:32:52 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecnew_from_func(
	size_t length,
	void *(*gen)(size_t),
	size_t elem_size)
{
	t_vector	*out;
	size_t		i;
	void		*new_elem;

	out = ft_vecnew_with_capacity(length, elem_size);
	out->length = length;
	i = 0;
	while (i < length)
	{
		new_elem = gen(i);
		ft_memcpy(ft_vecindex(out, i++), new_elem, elem_size);
		free(new_elem);
	}
	return (out);
}
