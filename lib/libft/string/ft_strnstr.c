/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:35:59 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:35:53 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	i;
	size_t	j;

	if (*n == 0)
		return ((char *)h);
	i = 0;
	while (h[i] && i < len)
	{
		j = 0;
		while (i + j < len && n[j] == h[i + j] && n[j])
			j++;
		if (ft_strlen(n) == j)
			return ((char *)&h[i]);
		i++;
	}
	return (0);
}
