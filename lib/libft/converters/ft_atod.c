/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:00:33 by gcrisp            #+#    #+#             */
/*   Updated: 2023/06/02 12:53:52 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(const char **s)
{
	if (**s == '+' || **s == '-')
	{
		*s += 1;
		if (*(*s - 1) == '-')
			return (-1);
	}
	return (1);
}

double	div_to_place(int n, int c)
{
	double	out;

	out = n;
	while (c--)
		out /= 10;
	return (out);
}

double	ft_atod(const char *str)
{
	int		sign;
	double	out;
	int		dc;

	while (ft_isspace(*str))
		str++;
	sign = check_sign(&str);
	out = 0;
	while (ft_isdigit(*str))
	{
		out = out * 10 + *str - '0';
		str++;
	}
	if (*str != '.')
		return (out * sign);
	str++;
	dc = 1;
	while (ft_isdigit(*str))
	{
		out += div_to_place(*str - '0', dc);
		str++;
		dc++;
	}
	return (out * sign);
}
