/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:09:23 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 16:13:50 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countgroups(const char *s, int (*p)(int c))
{
	size_t	out;
	size_t	i;

	out = 0;
	i = 0;
	while (s[i])
	{
		while (p(s[i]))
			i++;
		if (s[i])
		{
			out++;
			while (s[i] && !p(s[i]))
				i++;
		}
	}
	return (out);
}

char	**ft_split_by(char const *s, int (*p)(int c))
{
	char	**out;
	size_t	l;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	l = ft_countgroups(s, p);
	out = malloc(sizeof(char *) * (l + 1));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (i < l)
	{
		while (p(s[j]))
			j++;
		s = &s[j];
		j = 0;
		while (s[j] && !p(s[j]))
			j++;
		out[i++] = ft_strndup(s, j);
	}
	out[i] = 0;
	return (out);
}
