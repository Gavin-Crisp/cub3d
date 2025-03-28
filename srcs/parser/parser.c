/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:29:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 12:53:56 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_map(t_map **pmap)
{
	if ((*pmap)->wall_paths[0] && (*pmap)->wall_paths[1]
		&& (*pmap)->wall_paths[2] && (*pmap)->wall_paths[3]
		&& colour_get_t((*pmap)->ciel_colour) != 0xff
		&& colour_get_t((*pmap)->floor_colour) != 0xff)
		return (0);
	free_map(*pmap);
	*pmap = 0;
	return (1);
}

t_map	*parse(char *path)
{
	t_map	*map;
	char	*first_bounds_line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = new_map();
	first_bounds_line = parse_render_data(map, fd);
	if (!first_bounds_line)
	{
		close(fd);
		free_map(map);
		return (0);
	}
	if (check_map(&map))
		free(first_bounds_line);
	if (map && parse_bounds(map, first_bounds_line, fd))
	{
		free_map(map);
		map = 0;
	}
	close(fd);
	return (map);
}
