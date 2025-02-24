/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 08:59:12 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:36:17 by gcrisp           ###   ########.fr       */
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

char	*ft_strtrim(char const *s, char const *set)
{
	char	*out;
	int		start;
	int		end;
	int		l;

	if (!s)
		return (0);
	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	if (!s[start])
		return (makeempty());
	end = ft_strlen(s);
	while (ft_strrchr(set, s[end]) && end > 0)
		end--;
	l = end - start + 1;
	out = malloc(l + 1);
	if (!out)
		return (0);
	ft_strlcpy(out, &s[start], l + 1);
	return (out);
}
