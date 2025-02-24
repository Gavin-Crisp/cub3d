/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:18:48 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 15:43:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_util.h"

t_img	*new_image(void *mlx, int width, int height)
{
	t_img	*out;

	out = malloc(sizeof(t_img));
	out->img = mlx_new_image(mlx, width, height);
	out->addr = mlx_get_data_addr(out->img, &out->bytes_pp, &out->line_length,
			&out->endian);
	out->bytes_pp /= 8;
	out->width = width;
	out->height = height;
	return (out);
}

t_img	*new_image_xpm(void *mlx, char *rel_path)
{
	t_img	*out;

	out = malloc(sizeof(t_img));
	out->img = mlx_xpm_file_to_image(mlx, rel_path, &out->width, &out->height);
	out->addr = mlx_get_data_addr(out->img, &out->bytes_pp, &out->line_length,
			&out->endian);
	out->bytes_pp /= 8;
	return (out);
}

void	*pixel_address(t_img *img, size_t x, size_t y)
{
	return (img->addr + y * img->line_length + x * img->bytes_pp);
}

void	clear_image(t_img *img)
{
	ft_bzero(img->addr,
		pixel_address(img, img->width - 1, img->height - 1) - img->addr);
}
