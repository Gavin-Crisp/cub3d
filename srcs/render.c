/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 12:42:36 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_3d(t_map *map, t_img *img)
{
	(void)map;
	(void)img;
}

void	render_2d(t_map *map, t_img *img)
{
	t_point		**points;
	t_boundary	*bound;
	size_t		i;

	points = cast(map);
	i = 0;
	while (points[i])
	{
		put_point(points[i], 20, trgb_to_colour(255, 255, 0, 0), img);
		put_line(map->player_pos, points[i++], trgb_to_colour(122, 0, 0, 255),
			img);
	}
	i = 0;
	while (i < map->num_bounds)
	{
		bound = &map->bounds[i++];
		put_line(bound->end1, bound->end2, trgb_to_colour(255, 255, 255, 255),
			img);
		put_point(bound->end1, 10, trgb_to_colour(255, 255, 255, 255), img);
		put_point(bound->end2, 10, trgb_to_colour(255, 255, 255, 255), img);
	}
}
