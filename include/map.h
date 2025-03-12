/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 12:25:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 15:13:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H
# include <stdlib.h>
# include "casting.h"

typedef struct s_map
{
	t_point		player;
	float		facing_dir;
	t_boundary	*bounds;
	size_t		num_bounds;
	int			ciel_colour;
	int			floor_colour;
}	t_map;

t_map		*new_map(void);
void		free_map(t_map *map);

t_intsct	**cast(t_map *map);

#endif
