/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:28:17 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 14:39:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

int	trgb_to_colour(
	unsigned char t,
	unsigned char r,
	unsigned char g,
	unsigned char b
)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

unsigned char	colour_get_t(int col)
{
	return (((unsigned char *)&col)[3]);
}

unsigned char	colour_get_r(int col)
{
	return (((unsigned char *)&col)[2]);
}

unsigned char	colour_get_g(int col)
{
	return (((unsigned char *)&col)[1]);
}

unsigned char	colour_get_b(int col)
{
	return (((unsigned char *)&col)[0]);
}
