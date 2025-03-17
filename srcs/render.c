/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/13 14:23:44 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static size_t	get_rect_height(t_map *map, t_intsct *intsct, t_img *img)
{
	float	distance;

	distance = hypotf(map->player.x - intsct->pos.x,
			map->player.y - intsct->pos.y) * cosf(fmodf(
				map->facing_dir - intsct->angle + M_PI * 2, M_PI * 2));
	return (img->height
		* fminf(1, 2 * atan2f(1, 2 * distance) / map->vfov));
}

static int	get_col(t_intsct *intsct)
{
	int	col;
	int	mask;
	int	i;

	if (intsct->side == NORTH)
		col = GREEN;
	else if (intsct->side == EAST)
		col = YELLOW;
	else if (intsct->side == SOUTH)
		col = MAGENTA;
	else
		col = CYAN;
	mask = 0x00404040;
	i = rint(intsct->uv * 7);
	while (i--)
	{
		col = ~mask & col;
		mask = mask | mask >> 1;
	}
	return (col);
}

void	render_3d(t_map *map, t_vector *intscts, t_img *img)
{
	size_t		i;
	size_t		rect_left;
	size_t		rect_width;
	size_t		wall_height;
	t_intsct	*intsct;

	rect_left = (img->width % RAY_COUNT) / 2;
	rect_width = img->width / RAY_COUNT;
	i = 0;
	while (i < intscts->length)
	{
		intsct = ft_vecindex(intscts, i++);
		wall_height = get_rect_height(map, intsct, img);
		put_rect((t_pixel){rect_left, 0}, (t_pixel){rect_left + rect_width,
			(img->height - wall_height) / 2}, map->ciel_colour, img);
		put_rect((t_pixel){rect_left, (img->height - wall_height) / 2},
			(t_pixel){rect_left + rect_width,
			(img->height + wall_height) / 2}, get_col(intsct), img);
		put_rect((t_pixel){rect_left, (img->height + wall_height) / 2},
			(t_pixel){rect_left + rect_width, img->height},
			map->floor_colour, img);
		rect_left += rect_width;
	}
}

void	render_2d(t_map *map, t_vector *intscts, t_img *img)
{
	t_intsct	*intsct;
	size_t		i;
	int			col;

	i = 0;
	while (i < map->bounds->length)
		put_boundary(ft_vecindex(map->bounds, i++), WHITE, img);
	i = 0;
	while (i < intscts->length)
	{
		intsct = ft_vecindex(intscts, i);
		if (intsct->side == NORTH)
			col = GREEN;
		else if (intsct->side == EAST)
			col = YELLOW;
		else if (intsct->side == SOUTH)
			col = MAGENTA;
		else
			col = CYAN;
//		put_line(map->player, intscts[i]->pos, RED, img);
		put_point(intsct->pos, 10, col, img);
		i++;
	}
	put_point(map->player, 15, WHITE, img);
}
