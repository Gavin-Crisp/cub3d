/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 15:10:42 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	side_to_col(t_intsct *intsct)
{
	if (intsct->side == NORTH)
		return (GREEN);
	else if (intsct->side == EAST)
		return (YELLOW);
	else if (intsct->side == SOUTH)
		return (MAGENTA);
	else
		return (CYAN);
}

static size_t	get_rect_height(t_map *map, t_intsct *intsct, t_img *img)
{
	float	distance;

	distance = hypotf(map->player.x - intsct->pos.x,
					map->player.y - intsct->pos.y);
	return (img->height
		* fminf(1, 2 * atan2f(1, 2 * distance) / (FOV / 16 * 9 * DEG_TO_RAD_FACTOR)));
}

void	render_3d(t_map *map, t_intsct **intscts, t_img *img)
{
	size_t		i;
	size_t		rect_left;
	size_t		rect_width;
	size_t		rect_height;

	rect_left = (img->width % RAY_COUNT) / 2;
	rect_width = img->width / RAY_COUNT;
	i = 0;
	while (intscts[i])
	{
		rect_height = get_rect_height(map, intscts[i], img);
		put_rect((t_pixel){rect_left, (img->height - rect_height) / 2},
			(t_pixel){rect_left + rect_width,
			(img->height + rect_height) / 2 - 1},
			side_to_col(intscts[i]), img);
		rect_left += rect_width;
		i++;
	}
}

void	render_2d(t_map *map, t_intsct **intscts, t_img *img)
{
	size_t		i;

	i = 0;
	while (i < map->num_bounds)
		put_boundary(&map->bounds[i++], WHITE, img);
	i = 0;
	while (intscts[i])
	{
//		put_line(map->player, intscts[i]->pos, RED, img);
		put_point(intscts[i]->pos, 10, side_to_col(intscts[i]), img);
		i++;
	}
	put_point(map->player, 15, WHITE, img);
}
