/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 13:05:18 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

static void	snap_to_grid(t_point *p)
{
	p->x = round(p->x);
	p->y = round(p->y);
}

static void	put_hline(t_point a, t_point b, int col, t_img *img)
{
	int		*addr;
	size_t	i;
	size_t	len;

	if (a.x < b.x)
	{
		addr = pixel_address(img, a.x, a.y);
		len = b.x - a.x;
	}
	else
	{
		addr = pixel_address(img, b.x, b.y);
		len = a.x - b.x;
	}
	i = 0;
	while (i < len)
		addr[i++] = col;
}

static void	put_vline(t_point a, t_point b, int col, t_img *img)
{
	int		*addr;
	size_t	i;
	size_t	len;

	if (a.y < b.y)
	{
		addr = pixel_address(img, a.x, a.y);
		len = b.y - a.y;
	}
	else
	{
		addr = pixel_address(img, a.x, a.y);
		len = b.y - a.y;
	}
	i = 0;
	while (i++ < len)
	{
		*addr = col;
		addr += img->line_length;
	}
}

static void	put_line_helper(t_point a, int *pdx, int *pdy)
{
	if (*pdx > *pdy)
	{
		if (*pdx > 0)
			a.x += 1;
		else
			a.x -= 1;
	}
	else
	{
		if (*pdy > 0)
			a.y += 1;
		else
			a.y -= 1;
	}
}

void	put_line(t_point a, t_point b, int col, t_img *img)
{
	int	dx;
	int	dy;

	snap_to_grid(&a);
	snap_to_grid(&b);
	if (a.x == b.x)
		return (put_vline(a, b, col, img));
	if (a.y == b.y)
		return (put_hline(a, b, col, img));
	while (a.x != b.x && a.y != b.y)
	{
		put_pixel(img, a.x, a.y, col);
		dx = b.x - a.x;
		dy = b.y - a.y;
		put_line_helper(a, &dx, &dy);
	}			
}
