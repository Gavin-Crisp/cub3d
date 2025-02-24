/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 15:09:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

void	put_pixel(t_img *img, size_t x, size_t y, int col)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)dst = col;
}
