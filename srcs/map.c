/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 14:09:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(void)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player_start = (t_point){0, 0};
	out->start_dir = 0;
	out->bounds = ft_vecnew(sizeof(t_boundary));
	out->wall_paths[NORTH] = 0;
	out->wall_paths[EAST] = 0;
	out->wall_paths[SOUTH] = 0;
	out->wall_paths[WEST] = 0;
	out->ciel_colour = 0xff000000;
	out->floor_colour = 0xff000000;
	return (out);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	if (map->bounds)
		ft_vecfree(&map->bounds, 0);
	free(map->wall_paths[NORTH]);
	free(map->wall_paths[EAST]);
	free(map->wall_paths[SOUTH]);
	free(map->wall_paths[WEST]);
	free(map);
}
