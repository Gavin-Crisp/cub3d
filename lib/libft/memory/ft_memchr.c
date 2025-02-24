/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:25:00 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:32:32 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*sb;
	unsigned char	uc;

	sb = (unsigned char *)s;
	uc = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (sb[i] == uc)
			return ((void *)&sb[i]);
	}
	return (0);
}
