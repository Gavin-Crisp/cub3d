/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:42:27 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:36:47 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*makeempty(void)
{
	char	*out;

	out = malloc(1);
	out[0] = 0;
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;
	size_t	l;

	l = ft_strlen(s);
	if (l < start)
		return (makeempty());
	l -= start;
	if (len < l)
		l = len;
	out = malloc(l + 1);
	if (!out)
		return (0);
	i = -1;
	while (++i < l)
		out[i] = s[i + start];
	out[i] = 0;
	return (out);
}
