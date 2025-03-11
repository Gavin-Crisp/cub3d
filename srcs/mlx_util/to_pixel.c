/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:17:43 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:55:49 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

t_pixel	point_to_pixel(t_img *img, t_point p)
{
	p.x = round(coord_transform(p.x));
	p.y = round(coord_transform(p.y));
	if (p.x < 0)
		p.x = 0;
	else if (p.x >= img->width)
		p.x = img->width - 1;
	if (p.y < 0)
		p.y = 0;
	else if (p.y >= img->height)
		p.y = img->height - 1;
	return ((t_pixel){p.x, p.y});
}

size_t	coord_transform(float f)
{
	return (f * 50 + 30);
}
