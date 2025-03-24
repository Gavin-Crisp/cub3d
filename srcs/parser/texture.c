/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:01:21 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 14:02:16 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**get_var(char *paths[], char *line)
{
	if (line[0] == 'N' && line[1] == 'O')
		return (&paths[NORTH]);
	else if (line[0] == 'E' && line[1] == 'A')
		return (&paths[EAST]);
	else if (line[0] == 'S' && line[1] == 'O')
		return (&paths[SOUTH]);
	else if (line[0] == 'W' && line[1] == 'E')
		return (&paths[WEST]);
	return (0);
}

int	parse_texture_line(t_map *map, char *line)
{
	char	**var;
	size_t	len;

	len = ft_strlen(line);
	if (len < 4)
		return (1);
	var = get_var(map->wall_paths, line);
	if (!var || *var)
		return (1);
	*var = ft_strdup(&line[3]);
	if ((*var)[len - 4] == '\n')
		(*var)[len - 4] = 0;
	return (0);
}
