/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 09:30:03 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:27:19 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digcount(int n)
{
	int	i;

	if (n == -2147483648)
		return (10);
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int	ft_getdig(int n, int i)
{
	while (i-- > 0)
		n /= 10;
	if (n < 0)
		return (-(n % 10));
	return (n % 10);
}

char	*ft_itoa(int n)
{
	char	*out;
	int		dc;
	int		is_neg;
	int		i;

	dc = ft_digcount(n);
	is_neg = n < 0;
	out = malloc(dc + is_neg + 1);
	if (!out)
		return (0);
	i = -1;
	while (++i < dc)
		out[i + is_neg] = '0' + ft_getdig(n, dc - i - 1);
	out[i + is_neg] = 0;
	if (is_neg)
		out[0] = '-';
	return (out);
}
