/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:30:03 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 14:12:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digcount(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_getdig(unsigned long n, int i)
{
	while (i-- > 0)
		n /= 10;
	return (n % 10);
}

char	*ft_ultoa(unsigned long n)
{
	char	*out;
	int		dc;
	int		i;

	dc = ft_digcount(n);
	out = malloc(dc + 1);
	if (!out)
		return (0);
	i = -1;
	while (++i < dc)
		out[i] = '0' + ft_getdig(n, dc - i - 1);
	out[i] = 0;
	return (out);
}
