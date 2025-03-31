/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 15:29:12 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	get_col(t_intsct *intsct, t_rend *rend, float h_uv)
{
	t_img	*texture;
	size_t	x_index;
	size_t	y_index;

	texture = rend->walls[intsct->side];
	x_index = floorf(intsct->uv * texture->width);
	y_index = floorf(h_uv * texture->height);
	return (*(int *)pixel_address(texture, x_index, y_index));
}

static void	draw_slice(t_pixel start, size_t width, int colour, t_img *img)
{
	size_t	i;
	int		*addr;

	addr = pixel_address(img, start.x, start.y);
	i = 0;
	while (i < width)
		addr[i++] = colour;
}

static void	draw_wall(
	t_rend *rend,
	t_intsct *intsct,
	t_pixel left_width,
	t_img *img)
{
	float	wall_height;
	size_t	hv_offset;
	size_t	clipped_wh;
	size_t	i;
	t_pixel	wall_start;

	wall_height = round(intsct->height * img->height);
	clipped_wh = fmin(img->height, wall_height);
	hv_offset = (wall_height - clipped_wh) / 2;
	wall_start = (t_pixel){left_width.x, (img->height - clipped_wh) / 2};
	i = 0;
	while (i < clipped_wh)
	{
		draw_slice(wall_start, left_width.y,
			get_col(intsct, rend, (i++ + hv_offset) / wall_height), img);
		wall_start.y++;
	}
}

void	render_3d(t_rend *rend, t_vector *intscts, t_img *img)
{
	size_t		i;
	size_t		rect_left;
	size_t		rect_width;

	rect_left = (img->width % intscts->length) / 2;
	rect_width = img->width / intscts->length;
	i = 0;
	put_rect((t_pixel){0, 0}, (t_pixel){img->width, img->height / 2},
		rend->ciel, img);
	put_rect((t_pixel){0, img->height / 2},
		(t_pixel){img->width, img->height}, rend->floor, img);
	while (i < intscts->length)
	{
		draw_wall(rend, ft_vecindex(intscts, i++),
			(t_pixel){rect_left, rect_width}, img);
		rect_left += rect_width;
	}
}
