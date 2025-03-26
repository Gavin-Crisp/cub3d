/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:30:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 13:15:13 by gcrisp           ###   ########.fr       */
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

int	parse_map_line(t_map *map, char *line)
{
	static size_t	line_num = 0;
	size_t			i;

	if (!line)
	{
		line_num = 0;
		return (0);
	}
	i = 0;
	while (line[i])
	{
		if (line[i] == '1')
			push_bounds(i, line_num, map->bounds);
		i++;
	}
	line_num++;
	return (0);
}
