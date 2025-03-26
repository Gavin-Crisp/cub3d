/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:29:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 15:40:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_line(t_map *map, char *line)
{
	if (!line)
		return parse_map_line(map, line);
	if (line[0] == '\n')
		return (0);
	if (ft_isspace(line[0]) || line[0] == '1')
		return parse_map_line(map, line);
	else if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S'
		|| line[0] == 'W')
		return parse_texture_line(map, line);
	else if (line[0] == 'C' || line[0] == 'F')
		return parse_colour_line(map, line);
	return (1);
}

static t_map	*check_valid(t_map *map)
{
	if (!map)
		return (0);
	if (map->player_start.x != 0 && map->player_start.y != 0
		&& map->start_dir != -1 && map->bounds->length != 0
		&& map->wall_paths[NORTH] != 0 && map->wall_paths[EAST] != 0
		&& map->wall_paths[SOUTH] != 0 && map->wall_paths[WEST] != 0
		&& colour_get_t(map->ciel_colour) == 0
		&& colour_get_t(map->floor_colour) == 0)
		return (map);
	free_map(map);
	return (0);
}

t_map	*parse(char *path)
{
	t_map	*map;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	map = new_map();
	while (1)
	{
		line = get_next_line(fd);
		if (parse_line(map, line))
		{
			free_map(map);
			map = 0;
			break ;
		}
		if (!line)
			break ;
		free(line);
	}
	close(fd);
	return (check_valid(map));
}
