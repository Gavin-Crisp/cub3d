/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_consume.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 11:56:19 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 12:04:52 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_vecpush_consume(t_vector *vec, void *elem)
{
	int	res;

	res = ft_vecpush(vec, elem);
	free(elem);
	return (res);
}
