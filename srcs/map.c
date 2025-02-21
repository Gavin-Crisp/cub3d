/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:27:00 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 15:37:38 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	*new_map(float p_x, float p_y, t_boundary *bounds, size_t num_bounds)
{
	t_map	*out;

	out = malloc(sizeof(t_map));
	out->player_pos = new_point(p_x, p_y);
	out->facing_dir = 0;
	out->bounds = bounds;
	out->num_bounds = num_bounds;
	return (out);
}

void	free_map(t_map *map)
{
	if (!map)
		return ;
	free(map->player_pos)
	free_boundary_array(map->bounds);
	free(map);
}
