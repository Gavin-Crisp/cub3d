/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_pixel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 12:17:43 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 12:20:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

t_point	point_to_pixel_point(t_img *img, t_point p)
{
	t_point	out;

	out.x = round(coord_transform(p.x));
	out.y = round(coord_transform(p.y));
	if (out.x < 0)
		out.x = 0;
	else if (out.x >= img->width)
		out.x = img->width - 1;
	if (out.y < 0)
		out.y = 0;
	else if (out.y >= img->height)
		out.y = img->height - 1;
	return (out);
}

float	coord_transform(float f)
{
	return (f * 100 + 30);
}
