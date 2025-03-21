/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:50 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 13:49:12 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static void	p_bounds(t_map *map, size_t indent)
{
	char	*i_name;
	size_t	i;
	int		pad;

	pad = indent * INDENT;
	printf("%*ct_vector<t_boundary> *bounds: {\n", pad, ' ');
	indent++;
	i = 0;
	while (i < map->bounds->length)
	{
		i_name = ft_ultoa(i);
		debug_boundary(i_name, ft_vecindex(map->bounds, i++), indent);
		free(i_name);
	}
	printf("%*c}\n", pad, ' ');
}

static void	p_texts(t_map *map, size_t indent)
{
	int	pad;

	pad = indent * INDENT;
	printf("%*cchar *wall_texture_paths[4]: [\n", pad, ' ');
	pad += INDENT;
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[NORTH]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[EAST]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[SOUTH]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[WEST]);
	printf("%*c]\n", pad - INDENT, ' ');
}

void	debug_map(char *name, t_map *map, size_t indent)
{
	int	pad;

	pad = indent * INDENT;
	printf("%*ct_map *%s: {\n", pad, ' ', name);
	indent++;
	pad += INDENT;
	debug_point("player_start", map->player_start, indent);
	printf("%*cfloat start_dir: %f\n", pad, ' ', map->start_dir);
	p_bounds(map, indent);
	p_texts(map, indent);
	printf("%*cint ciel_colour: %d\n", pad, ' ', map->ciel_colour);
	printf("%*cint floor_colour: %d\n", pad, ' ', map->floor_colour);
	printf("%*c}\n", pad - INDENT, ' ');
}
