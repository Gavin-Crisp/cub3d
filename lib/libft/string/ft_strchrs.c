/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:00:30 by gcrisp            #+#    #+#             */
/*   Updated: 2024/02/08 15:10:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchrs(const char *s, const char *cs)
{
	size_t	i;
	size_t	j;

	i = -1;
	if (!cs)
		return (0);
	while (s[++i])
	{
		j = -1;
		while (cs[++j])
		{
			if (s[i] == cs[j])
				return ((char *)&s[i]);
		}
	}
	if (s[i] == cs[0])
		return ((char *)&s[i]);
	return (0);
}
