/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:08:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 15:11:01 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

put_pixel(t_img *img, int x, int y, int col)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
