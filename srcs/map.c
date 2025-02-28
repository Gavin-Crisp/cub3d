/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 13:29:16 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(t_point player, t_boundary *bounds, size_t num_bounds)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player = player;
	out->facing_dir = 0;
	out->bounds = bounds;
	out->num_bounds = num_bounds;
	return (out);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free(map->bounds);
	free(map);
}

t_intsct	**cast(t_map *map)
{
	t_intsct	**intscts;
	t_ray		*ray;
	float		ray_step;
	float		ray_dir;
	size_t		i;

	ray_step = FOV / RAY_COUNT;
	ray_dir = map->facing_dir - FOV / 2;
	i = 0;
	intscts = ft_calloc(RAY_COUNT + 1, sizeof(t_intsct));
	while (i < RAY_COUNT)
	{
		ray = new_ray((t_point){map->player.x, map->player.y},
				ray_dir);
		ray_dir += ray_step;
		intscts[i++] = get_closest_intsct(ray,
				get_intersections(ray, map->bounds, map->num_bounds));
		free(ray);
	}
	return (intscts);
}
