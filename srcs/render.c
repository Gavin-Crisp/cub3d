/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 13:17:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_3d(t_map *map, t_img *img)
{
	(void)map;
	(void)img;
}

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

void	render_2d(t_map *map, t_img *img)
{
	t_intsct	**intscts;
	t_boundary	*bound;
	size_t		i;

	intscts = cast(map);
	i = -1;
	while (intscts[++i])
	{
		put_point(intscts[i]->pos, 20, side_to_col(intscts[i]), img);
		put_line(map->player, intscts[i]->pos, side_to_col(intscts[i]), img);
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
