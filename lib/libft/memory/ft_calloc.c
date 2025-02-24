/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:57:40 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:32:25 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;
	size_t	bytes;

	bytes = count * size;
	p = malloc(bytes);
	if (!p)
		return (0);
	i = -1;
	while (++i < bytes)
		((char *)p)[i] = 0;
	return (p);
}
