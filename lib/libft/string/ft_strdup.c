/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:38:21 by gcrisp            #+#    #+#             */
/*   Updated: 2024/10/31 12:26:24 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*out;
	size_t	i;

	if (!s1)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	out = malloc(i + 1);
	if (!out)
		return (0);
	out[i] = 0;
	while (i-- > 0)
		out[i] = s1[i];
	return (out);
}
