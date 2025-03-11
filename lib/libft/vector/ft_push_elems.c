/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_elems.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:11 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:36:11 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vec_push_elems(t_vector *vec, void *elems, size_t elem_count)
{
	return (ft_vecinsert_elems(vec, elems, elem_count, vec->length - 1));
}
