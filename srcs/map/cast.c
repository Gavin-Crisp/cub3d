/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 13:33:01 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 15:48:48 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_point	a_to_p(t_point p, float angle)
{
	return ((t_point){p.x + cosf(angle), p.y + sinf(angle)});
}

static t_point	get_step(t_point target, t_map *map, size_t ray_count)
{
	t_point	target_2;

	target_2 = a_to_p(map->player,
			fmodf(map->facing_dir + map->fov / 2, M_PI * 2));
	return ((t_point){(target_2.x - target.x) / ray_count,
		(target_2.y - target.y) / ray_count});
}

static t_ray	*get_rays(t_map *map, size_t ray_count)
{
	t_point		target;
	t_point		step;
	t_ray		*rays;
	size_t		i;
	float		theta;

	target = a_to_p(map->player,
			fmodf(map->facing_dir - map->fov / 2 + M_PI * 2, M_PI * 2));
	step = get_step(target, map, ray_count);
	rays = malloc(sizeof(t_ray) * ray_count);
	i = 0;
	while (i < ray_count)
	{
		theta = atan2f(target.y - map->player.y, target.x - map->player.x);
		rays[i++] = (t_ray){map->player, a_to_p(map->player, theta), theta};
		target.x += step.x;
		target.y += step.y;
	}
	return (rays);
}

t_vector	*cast(t_map *map)
{
	t_vector	*closest_intscts;
	t_intsct	*closest;
	t_ray		*rays;
	size_t		i;

	closest_intscts = ft_vecnew_with_capacity(RAY_COUNT, sizeof(t_intsct));
	rays = get_rays(map, RAY_COUNT);
	i = 0;
	while (i < RAY_COUNT)
	{
		closest = get_closest_intsct(&rays[i], map->bounds);
		if (closest)
			ft_vecpush_consume(closest_intscts, closest);
		i++;
	}
	free(rays);
	return (closest_intscts);
}
