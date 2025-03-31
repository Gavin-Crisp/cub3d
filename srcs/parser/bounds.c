/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bounds.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:56:11 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/31 15:00:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	parse_bounds(t_map *map, char *line, int fd)
{
	size_t  line_num;

	line_num = 0;
	while (line && line[0] != '\n')
	{
		if (parse_map_line(map, line, line_num++))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
