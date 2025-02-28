/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hvline_rect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:04:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 13:47:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

static void	do_rect(t_point a, t_point b, int col, t_img *img)
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

void	put_rect(t_point a, t_point b, int col, t_img *img)
{
	point_to_pixel_point(img, &a);
	point_to_pixel_point(img, &b);
	if (a.x == b.x || a.y == b.y)
		return ;
	if (a.x > b.x)
		ft_memswap(&a.x, &b.x, sizeof(float));
	if (a.y > b.y)
		ft_memswap(&a.y, &b.y, sizeof(float));
	do_rect(a, b, col, img);
}

void	put_hline(t_point a, size_t len, int col, t_img *img)
{
	t_point	b;

	if (!len)
		return ;
	point_to_pixel_point(img, &a);
	b = (t_point){a.x + len, a.y + (LINE_STROKE - 1) / 2};
	a.y -= (LINE_STROKE - 1) / 2;
	if (a.y < 0)
		a.y = 0;
	if (b.x >= img->width)
		b.x = img->width - 1;
	if (b.y >= img->height)
		b.y = img->height - 1;
	do_rect(a, b, col, img);
}

void	put_vline(t_point a, size_t len, int col, t_img *img)
{
	t_point	b;

	if (!len)
		return ;
	point_to_pixel_point(img, &a);
	b = (t_point){a.x + (LINE_STROKE - 1) / 2, a.y + len};
	a.x -= (LINE_STROKE - 1) / 2;
	if (a.x < 0)
		a.x = 0;
	if (b.x >= img->width)
		b.x = img->width - 1;
	if (b.y >= img->height)
		b.y = img->height - 1;
	do_rect(a, b, col, img);
}
