/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:10:18 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:35:32 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*out;

	if (!s)
		return (0);
	out = malloc(ft_strlen(s) + 1);
	if (!out)
		return (0);
	i = -1;
	while (s[++i])
		out[i] = f(i, s[i]);
	out[i] = 0;
	return (out);
}
