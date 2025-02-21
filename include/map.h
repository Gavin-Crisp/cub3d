/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 14:15:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include "casting.h"

typedef struct s_map
{
	t_point		*player_pos;
	double		facing_dir;
	t_boundary	*bounds;
	size_t		num_bounds;
}	t_map;

t_map	*new_map(double p_x, double p_y, t_boundary *bounds, size_t num_bounds);
void	free_map(t_map *map);

#endif
