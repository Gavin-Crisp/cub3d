/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:03:39 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 13:29:18 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_point	**cast(t_map *map)
{
	t_point	*intersections;
	t_ray	*ray;
	float	ray_step;
	float	ray_dir;
	size_t	i;

	ray_step = FOV / RAY_COUNT;
	ray_dir = map->facing_dir - FOV / 2;
	i = 0;
	while (i < RAY_COUNT)
	{
		ray = new_ray(map->player_pos->x, map_player_pos->y, ray_dir);
		intersections[i++] = get_closest_point(
			get_instersections(ray, map->bounds, map->num_bounds));
		free(ray);
	}
	return (intersections);
}
