/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 13:43:18 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

void	put_pixel(t_img *img, size_t x, size_t y, int col)
{
	*(unsigned int *)pixel_address(img, x, y) = col;
}

void	put_point(t_point p, size_t size, int col, t_img *img)
{
	t_point	a;
	t_point	b;

	a.x = p.x - (size - 1) / 2;
	a.y = p.y - (size - 1) / 2;
	b.x = p.x + (size - 1) / 2;
	b.y = p.y + (size - 1) / 2;
	put_rect(a, b, col, img);
}
