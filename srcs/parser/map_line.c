/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 15:30:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/03 15:31:48 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_player(t_map *map, char *line, size_t line_num, size_t i)
{
	if (map->start_dir != -1)
		return (1);
	map->player_start = (t_point){i + 0.5f, line_num + 0.5f};
	if (line[i] == 'N')
		map->start_dir = 3 * M_PI_2;
	else if (line[i] == 'E')
		map->start_dir = 0;
	else if (line[i] == 'S')
		map->start_dir = M_PI_2;
	else if (line[i] == 'W')
		map->start_dir = M_PI;
	return (0);
}

static size_t	parse_wall(
	t_vector *bounds,
	char *line,
	size_t i,
	size_t line_num)
{
	size_t	start;

	if (i && line[i - 1] == '0')
	{
		ft_vecpush_consume(bounds, new_boundary((t_point){i, line_num},
				(t_point){i, line_num + 1}));
	}
	start = i;
	while (line[i] == '1')
		i++;
	ft_vecpush_consume(bounds, new_boundary((t_point){start, line_num},
			(t_point){i, line_num}));
	ft_vecpush_consume(bounds, new_boundary((t_point){start, line_num + 1},
			(t_point){i, line_num + 1}));
	if (line [i] == '0')
	{
		ft_vecpush_consume(bounds, new_boundary((t_point){i, line_num},
				(t_point){i, line_num + 1}));
	}
	return (i);
}

static size_t	parse_outside(char *line, char *prev_line, size_t i)
{
	size_t	j;

	if (i && is_inside(line[i - 1]))
		return (-1);
	j = 0;
	while (prev_line[j] && j < i)
		j++;
	if (prev_line[j])
	{
		while (is_outside(line[i]) && prev_line[i])
		{
			if (is_inside(prev_line[i]))
				return (-1);
			i++;
		}
	}
	while (is_outside(line[i]))
		i++;
	if (is_inside(line[i]))
		return (-1);
	return (i);
}

static size_t	parse_inside(char *line, char *prev_line, size_t i)
{
	size_t	j;

	if (!i || is_outside(line[i - 1]))
		return (-1);
	j = 0;
	while (prev_line[j] && j < i)
		j++;
	if (!prev_line[j])
		return (-1);
	while (is_empty(line[i]))
	{
		if (!prev_line[i] || prev_line[i] == '\n' || is_outside(prev_line[i]))
			return (-1);
		i++;
	}
	if (!line[i] || line[i] == '\n' || is_outside(line[i]))
		return (-1);
	return (i);
}

int	parse_map_line(t_map *map, char *line, char *prev_line, size_t line_num)
{
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (is_outside(line[i]))
			i = parse_outside(line, prev_line, i);
		else if (is_inside(line[i]))
		{
			if (is_player(line[i]))
			{
				if (parse_player(map, line, line_num, i++))
					return (1);
			}
			i = parse_inside(line, prev_line, i);
		}
		else if (line[i] == '1')
			i = parse_wall(map->bounds, line, i, line_num);
		else
			return (1);
		if (i == (size_t) - 1)
			return (1);
	}
	return (0);
}
