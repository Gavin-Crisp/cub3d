/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 14:34:08 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:27:59 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	num_chars(int n, size_t base_num)
{
	size_t	i;

	i = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= base_num;
		i++;
	}
	if (n < 0)
		i++;
	return (i);
}

static int	num_at(int num, int index, size_t base)
{
	while (index > 0)
		num /= base;
	if (num < 0)
		return (-(num % base));
	return (num % base);
}

char	*ft_itoa_base(int n, char *base)
{
	char	*out;
	size_t	blen;
	int		i;
	int		len;

	blen = ft_strlen(base);
	if (blen < 2)
		return (0);
	len = num_chars(n, blen);
	out = malloc(len + 1 + (n < 0));
	i = -1;
	if (n < 0)
	{
		out[0] = '-';
		i++;
		len++;
	}
	while (++i < len)
		out[i] = base[num_at(n, len - i - 1, blen)];
	out[i] = 0;
	return (out);
}
