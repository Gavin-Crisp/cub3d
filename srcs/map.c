/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/12 15:05:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(void)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player = (t_point){0, 0};
	out->facing_dir = 0;
	out->bounds = 0;
	out->num_bounds = 0;
	out->ciel_colour = 0;
	out->floor_colour = 0;
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
	float		ray_dir;
	size_t		i;

	ray_dir = fmodf(map->facing_dir - FOV / 2 + M_PI * 2, M_PI * 2);
	i = 0;
	intscts = malloc(sizeof(t_intsct) * (RAY_COUNT + 1));
	intscts[RAY_COUNT] = 0;
	while (i < RAY_COUNT)
	{
		ray = new_ray(map->player, ray_dir);
		ray_dir += fmodf(FOV / RAY_COUNT, M_PI * 2);
		intscts[i++] = get_closest_intsct(ray,
				get_intersections(ray, map->bounds, map->num_bounds));
		free(ray);
	}
	return (intscts);
}
