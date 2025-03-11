/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_elems.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 10:31:06 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 10:31:07 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_vecpop_elems(t_vector *vec, size_t num_elems)
{
	return (ft_vecremove_elems(vec, vec->length - 1, num_elems));
}
