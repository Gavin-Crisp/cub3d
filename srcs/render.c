/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 15:06:09 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"
#include "debug.h"

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

void	render_3d(t_map *map, t_img *img)
{
	(void)map;
	(void)img;
}

void	render_2d(t_map *map, t_img *img)
{
	t_intsct	**intscts;
	t_boundary	*bound;
	size_t		i;

	i = 0;
	while (i < map->num_bounds)
	{
		bound = &map->bounds[i++];
		put_line(bound->end1, bound->end2, WHITE, img);
		put_point(bound->end1, 11, WHITE, img);
		put_point(bound->end2, 11, WHITE, img);
	}
	intscts = cast(map);
	i = 0;
	while (intscts[i])
	{
//		put_line(map->player, intscts[i]->pos, RED, img);
		put_point(intscts[i]->pos, 10, side_to_col(intscts[i]), img);
		i++;
	}
	put_point(map->player, 15, WHITE, img);
}
