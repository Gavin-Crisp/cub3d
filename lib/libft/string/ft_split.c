/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:09:23 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:34:11 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countgroups(const char *s, char c)
{
	size_t	out;
	size_t	i;

	out = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			out++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (out);
}

char	**ft_split(char const *s, char c)
{
	char	**out;
	size_t	l;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	l = ft_countgroups(s, c);
	out = malloc(sizeof(char *) * (l + 1));
	if (!out)
		return (0);
	i = 0;
	j = 0;
	while (i < l)
	{
		while (s[j] == c)
			j++;
		s = &s[j];
		j = 0;
		while (s[j] != c && s[j])
			j++;
		out[i++] = ft_strndup(s, j);
	}
	out[i] = 0;
	return (out);
}
