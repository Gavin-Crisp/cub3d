/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:44:08 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

static void	vstroke(t_pixel p, int col, t_img *img)
{
	int		*addr;
	size_t	height;

	p.y -= (LINE_STROKE - 1) / 2;
	height = img->height - p.y;
	if (height > LINE_STROKE)
		height = LINE_STROKE;
	while (height--)
	{
		addr = pixel_address(img, p.x, p.y++);
		*addr = col;
	}
}

static void	hstroke(t_pixel p, int col, t_img *img)
{
	int		*addr;
	size_t	i;
	size_t	width;

	i = 0;
	p.x -= (LINE_STROKE - 1) / 2;
	width = img->width - p.x;
	if (width > LINE_STROKE)
		width = LINE_STROKE;
	addr = pixel_address(img, p.x, p.y);
	while (i < width)
		addr[i++] = col;
}

static void	put_line_helper(t_pixel *n, t_pixel b, float m, int steep)
{
	float	ndy;
	float	ndx;
	float	nm;

	ndy = b.y - n->y;
	ndx = b.x - n->x;
	if (!ndy)
		n->x++;
	else if (!ndx)
		n->y++;
	if (!ndy || !ndx)
		return ;
	nm = ndy / ndx;
	if (nm == m && steep)
		n->y++;
	else if (nm == m)
		n->x++;
	else if (nm > m && b.y > n->y)
		n->y++;
	else if (nm > m)
		n->x++;
	else if (nm < m && b.y > n->y)
		n->x++;
	else
		n->y++;
}

static void	do_line(t_pixel a, t_pixel b, int col, t_img *img)
{
	float	dx;
	float	dy;
	float	m;
	int		steep;
	t_pixel	n;

	dx = b.x - a.x;
	dy = b.y - a.y;
	m = dy / dx;
	steep = fabsf(dy) > fabsf(dx);
	n = a;
	while (n.x != b.x || n.y != b.y)
	{
		if (steep)
			hstroke(n, col, img);
		else
			vstroke(n, col, img);
		put_line_helper(&n, b, m, steep);
	}
}

void	put_line(t_pixel a, t_pixel b, int col, t_img *img)
{
	if (a.x > b.x)
		ft_memswap(&a, &b, sizeof(t_pixel));
	if (a.y == b.y)
		return (put_hline(a, b.x - a.x, col, img));
	if (a.x == b.x && a.y < b.y)
		return (put_vline(a, b.y - a.y, col, img));
	else if (a.x == b.x)
		return (put_vline(b, a.y - b.y, col, img));
	do_line(a, b, col, img);
}
