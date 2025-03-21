/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:20:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 11:03:46 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	init_rd(t_rend *rd, void *mlx, t_map *map)
{
	rd->walls[NORTH] = new_image_xpm(mlx, map->wall_paths[NORTH]);
	rd->walls[EAST] = new_image_xpm(mlx, map->wall_paths[EAST]);
	rd->walls[SOUTH] = new_image_xpm(mlx, map->wall_paths[SOUTH]);
	rd->walls[WEST] = new_image_xpm(mlx, map->wall_paths[WEST]);
	rd->ciel = map->ciel_colour;
	rd->floor = map->floor_colour;
}
