/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:30:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 15:44:28 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	push_bounds(size_t x, size_t y, t_vector *vec)
{
	ft_vecpush_consume(vec, new_boundary((t_point) {x, y},
			(t_point){x + 1, y}));
	ft_vecpush_consume(vec, new_boundary((t_point) {x + 1, y},
			(t_point){x + 1, y + 1}));
	ft_vecpush_consume(vec, new_boundary((t_point) {x + 1, y + 1},
			(t_point){x, y + 1}));
	ft_vecpush_consume(vec, new_boundary((t_point) {x, y + 1},
			(t_point){x, y}));
}

static void	letter_to_dir(t_map *map, char c)
{
	if (c == 'N')
		map->start_dir = 3 * M_PI_2;
	else if (c == 'E')
	 	map->start_dir = 0;
	else if (c == 'S')
		map->start_dir = M_PI_2;
	else
		map->start_dir = M_PI;
}

int	parse_map_line(t_map *map, char *line)
{
	static size_t	line_num = 0;
	size_t			i;

	if (!line)
		return (0);
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			push_bounds(i, line_num, map->bounds);
		if (line[i] == 'N' || line[i] == 'E' || line[i] == 'S'
			|| line[i] == 'W')
		{
			if (map->start_dir != -1)
				return (1);
			map->player_start = (t_point){i + 0.5f, line_num + 0.5f};
			letter_to_dir(map, line[i]);
		}
		i++;
	}
	line_num++;
	return (0);
}
