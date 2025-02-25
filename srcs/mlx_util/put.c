/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 12:24:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

void	put_pixel(t_img *img, size_t x, size_t y, int col)
{
	*(unsigned int *)pixel_address(img, x, y) = col;
}

static t_point	*snap_to_grid(t_point *p)
{
	return (new_point(round(p->x), round(p->y)));
}

void	put_point(t_point *p, size_t size, int col, t_img *img)
{
	int		*addr;
	size_t	width;
	size_t	height;
	size_t	i;
	size_t	j;

	p = snap_to_grid(p);
	addr = pixel_address(img, p->x, p->y);
	i = 0;
	width = size;
	height = size;
	if (p->x + width > img->width)
		width = img->width - p->x;
	if (p->y + height > img->height)
		height = img->height - p->y;
	while (i < height)
	{
		j = 0;
		while (j < width)
			addr[j++] = col;
		addr += img->line_length;
	}
}
