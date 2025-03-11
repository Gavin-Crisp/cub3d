/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:40:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

void	put_pixel(t_pixel p, int col, t_img *img)
{
	*(unsigned int *)pixel_address(img, p.x, p.y) = col;
}

void	do_point(t_pixel a, t_pixel b, int col, t_img *img)
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
	t_pixel	a;
	t_pixel	b;

	b = point_to_pixel(img, p);
	a = point_to_pixel(img, p);
	if (a.x < (size - 1) / 2)
		a.x = 0;
	else
		a.x -= (size - 1) / 2;
	if (a.y < (size - 1) / 2)
		a.y = 0;
	else
		a.y -= (size - 1) / 2;
	b.x += (size - 1) / 2;
	b.y += (size - 1) / 2;
	if (b.x >= (size_t)img->width)
		b.x = img->width - 1;
	if (b.y >= (size_t)img->height)
		b.y = img->height - 1;
	do_point(a, b, col, img);
}

void	put_boundary(t_boundary *bound, int col, t_img *img)
{
	t_pixel	end1;
	t_pixel	end2;

	put_point(bound->end1, 11, col, img);
	put_point(bound->end2, 11, col, img);
	end1 = point_to_pixel(img, bound->end1);
	end2 = point_to_pixel(img, bound->end2);
	if (end1.x == end2.x)
	{
		end1.x -= 2;
		end2.x += 2;
	}
	else if (end1.y == end2.y)
	{
		end1.y -= 2;
		end2.y += 2;
	}
	put_rect(end1, end2, col, img);
}
