/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 14:45:19 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include <math.h>
# include "casting.h"

// wall_textures is arranged NESW
typedef struct s_map
{
	t_point		player;
	float		facing_dir;
	float		fov;
	float		vfov;
	t_vector	*bounds;
	char		*wall_textures[4];
	int			ciel_colour;
	int			floor_colour;
}	t_map;

t_map		*new_map(void);
void		free_map(t_map *map);

t_vector	*cast(t_map *map);

#endif
