/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 13:34:33 by gcrisp           ###   ########.fr       */
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
