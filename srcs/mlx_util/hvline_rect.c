/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hvline_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:04:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:33:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

static void	do_rect(t_pixel a, t_pixel b, int col, t_img *img)
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

void	put_rect(t_pixel a, t_pixel b, int col, t_img *img)
{
	if (a.x == b.x || a.y == b.y)
		return ;
	if (a.x > b.x)
		ft_memswap(&a.x, &b.x, sizeof(float));
	if (a.y > b.y)
		ft_memswap(&a.y, &b.y, sizeof(float));
	do_rect(a, b, col, img);
}

void	put_hline(t_pixel p, size_t len, int col, t_img *img)
{
	t_pixel	b;

	if (!len)
		return ;
	b = (t_pixel){p.x + len, p.y + (LINE_STROKE - 1) / 2};
	p.y -= (LINE_STROKE - 1) / 2;
	if (b.x >= (size_t)img->width)
		b.x = img->width - 1;
	if (b.y >= (size_t)img->height)
		b.y = img->height - 1;
	do_rect(p, b, col, img);
}

void	put_vline(t_pixel p, size_t len, int col, t_img *img)
{
	t_pixel	b;

	if (!len)
		return ;
	b = (t_pixel){p.x + (LINE_STROKE - 1) / 2, p.y + coord_transform(len)};
	p.x -= (LINE_STROKE - 1) / 2;
	if (b.x >= (size_t)img->width)
		b.x = img->width - 1;
	if (b.y >= (size_t)img->height)
		b.y = img->height - 1;
	do_rect(p, b, col, img);
}
