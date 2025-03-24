/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:29:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 14:04:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_map_line(t_map *map, char *line)
{
	(void)map;
	(void)line;
	return (0);
}

static int	parse_line(t_map *map, char *line)
{
	if (ft_isspace(line[0]) || line[0] == '1')
		return parse_map_line(map, line);
	else if (line[0] == 'N' || line[0] == 'E' || line[0] == 'S'
		|| line[0] == 'W')
		return parse_texture_line(map, line);
	else if (line[0] == 'C' || line[0] == 'F')
		return parse_colour_line(map, line);
	return (1);
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
	line = get_next_line(fd);
	while (line)
	{
		if (parse_line(map, line))
		{
			free_map(map);
			return (0);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (map);
}
