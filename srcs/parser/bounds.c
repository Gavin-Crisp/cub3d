/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:56:11 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/03 11:10:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	check_first(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (is_inside(line[i++]))
		{
			free(line);
			return (1);
		}
	}
	return (0);
}

static int	check_last(char *line)
{
	size_t	start;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		while (is_outside(line[i]))
			i++;
		start = i;
		while (line[i] == '1')
			i++;
		if (!(is_outside(line[i]) || line[i] == '\n' || !line[i]))
		{
			free(line);
			return (1);
		}
	}
	free(line);
	return (0);
}

int	parse_bounds(t_map *map, char *prev_line, int fd)
{
	size_t  line_num;
	char	*line;

	line_num = 0;
	if (check_first(prev_line))
		return (1);
	line = get_next_line(fd);
	while (line && line[0] != '\n')
	{
		if (parse_map_line(map, line, prev_line, line_num++))
		{
			free(prev_line);
			free(line);
			return (1);
		}
		free(prev_line);
		prev_line = line;
		line = get_next_line(fd);
	}
	return (check_last(prev_line));
}
