/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_with_capacity.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:02 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:31:03 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector	*ft_vecnew_with_capacity(size_t capacity, size_t elem_size)
{
	t_vector	*out;

	out = ft_vecnew(elem_size);
	ft_vecreserve(out, capacity);
	return (out);
}
