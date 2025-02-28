/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 12:06:59 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

void	put_pixel(t_img *img, size_t x, size_t y, int col)
{
	*(unsigned int *)pixel_address(img, x, y) = col;
}

void	do_point(t_point a, t_point b, int col, t_img *img)
{
	size_t	width;
	size_t	height;
	size_t	i;
	int		*addr;

	width = b.x - a.x;
	height = b.y - a.y;
	while (height--)
	{
		addr = pixel_address(img, a.x, a.y++);
		i = 0;
		while (i < width)
			addr[i++] = col;
	}
}

void	put_point(t_point p, size_t size, int col, t_img *img)
{
	t_point	a;
	t_point	b;

	p = point_to_pixel_point(img, p);
	a.x = p.x - (size - 1) / 2;
	a.y = p.y - (size - 1) / 2;
	if (a.x < 0)
		a.x = 0;
	if (a.y < 0)
		a.y = 0;
	b.x = p.x + (size - 1) / 2;
	b.y = p.y + (size - 1) / 2;
	if (b.x >= img->width)
		b.x = img->width - 1;
	if (b.y >= img->height)
		b.y = img->height - 1;
	do_point(a, b, col, img);
}
