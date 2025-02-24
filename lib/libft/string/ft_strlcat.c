/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:20:56 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:34:58 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = 0;
	if (i + j < dstsize - 1 && dstsize && src[j])
	{
		while (i + j < dstsize - 1 && dstsize && src[j])
		{
			dst[i + j] = src[j];
			j++;
		}
		dst[i + j] = 0;
	}
	while (src[j])
		j++;
	return (i + j);
}
