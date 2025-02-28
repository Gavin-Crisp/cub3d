/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 15:35:48 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

static void	vstroke(t_point p, int col, t_img *img)
{
	int		*addr;
	size_t	i;

	i = 0;
	while (i++ < LINE_STROKE)
	{
		addr = pixel_address(img, p.x, p.y++);
		*addr = col;
	}
}

static void	hstroke(t_point p, int col, t_img *img)
{
	int		*addr;
	size_t	i;

	i = 0;
	addr = pixel_address(img, p.x, p.y);
	while (i < LINE_STROKE)
		addr[i++] = col;
}

static void	put_line_helper(t_point *n, t_point b, float m, int steep)
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

static void	do_line(t_point a, t_point b, int col, t_img *img)
{
	float	dx;
	float	dy;
	float	m;
	int		steep;
	t_point	n;

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

void	put_line(t_point a, t_point b, int col, t_img *img)
{
	if (a.x > b.x)
		ft_memswap(&a, &b, sizeof(t_point));
	if (a.y == b.y)
		return (put_hline(a, b.x - a.x, col, img));
	if (a.x == b.x && a.y < b.y)
		return (put_vline(a, b.y - a.y, col, img));
	else if (a.x == b.x)
		return (put_vline(b, a.y - b.y, col, img));
	point_to_pixel_point(img, &a);
	point_to_pixel_point(img, &b);
	do_line(a, b, col, img);
}
