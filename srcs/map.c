/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 13:00:33 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(void)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player = (t_point){0, 0};
	out->facing_dir = 0;
	out->fov = M_PI_2;
	out->vfov = M_PI_2 / 16 * 9;
	out->bounds = ft_vecnew(sizeof(t_boundary));
	out->wall_textures[0] = 0;
	out->wall_textures[1] = 0;
	out->wall_textures[2] = 0;
	out->wall_textures[3] = 0;
	out->ciel_colour = 0;
	out->floor_colour = 0;
	return (out);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	ft_vecfree(&map->bounds, 0);
	free(map);
}

static void	do_cast(t_vector *best_intscts, t_ray *ray, t_vector *bounds)
{
	t_vector	*all_intscts;
	t_intsct	*intsct;

	all_intscts = get_intersections(ray, bounds);
	intsct = get_closest_intsct(ray, all_intscts);
	ft_vecfree(&all_intscts, 0);
	if (intsct)
		ft_vecpush_consume(best_intscts, intsct);
}

t_vector	*cast(t_map *map)
{
	t_vector	*best_intscts;
	t_ray		ray;
	float		ray_step;
	float		ray_dir;
	size_t		i;

	ray_dir = fmodf(map->facing_dir - map->fov / 2 + M_PI * 2, M_PI * 2);
	ray_step = map->fov / RAY_COUNT;
	i = 0;
	best_intscts = ft_vecnew_with_capacity(RAY_COUNT, sizeof(t_intsct));
	while (i++ < RAY_COUNT)
	{
		ray = (t_ray){map->player, (t_point){map->player.x + cosf(ray_dir),
			map->player.y + sinf(ray_dir)}, ray_dir};
		ray_dir = fmodf(ray_dir + ray_step, M_PI * 2);
		do_cast(best_intscts, &ray, map->bounds);
	}
	return (best_intscts);
}
