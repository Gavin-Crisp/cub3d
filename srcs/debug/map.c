/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:50 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 16:30:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static void	p_bounds(t_vector *bounds, size_t indent)
{
	char	*i_name;
	size_t	i;
	int		pad;

	pad = indent * INDENT;
	if (bounds->length == 0)
	{
		printf("%*ct_vector<t_boundary> *bounds: { }\n", pad, ' ');
		return ;
	}
	printf("%*ct_vector<t_boundary> *bounds: {\n", pad, ' ');
	indent++;
	i = 0;
	while (i < bounds->length)
	{
		i_name = ft_ultoa(i);
		debug_boundary(i_name, ft_vecindex(bounds, i++), indent);
		free(i_name);
	}
	printf("%*c}\n", pad, ' ');
}

static void	p_texts(t_map *map, size_t indent)
{
	int	pad;

	pad = indent * INDENT;
	printf("%*cchar *wall_paths[4]: [\n", pad, ' ');
	pad += INDENT;
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[NORTH]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[EAST]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[SOUTH]);
	printf("%*c\"%s\"\n", pad, ' ', map->wall_paths[WEST]);
	printf("%*c]\n", pad - INDENT, ' ');
}

static void	p_colour(char *name, int colour, int pad)
{
	printf("%*ct_colour(trgb) %s: %02X|%02X|%02X|%02X\n", pad, ' ', name,
		colour_get_t(colour), colour_get_r(colour), colour_get_g(colour),
		colour_get_b(colour));
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
	p_bounds(map->bounds, indent);
	p_texts(map, indent);
	p_colour("ciel_colour", map->ciel_colour, pad);
	p_colour("floor_colour", map->floor_colour, pad);
	printf("%*c}\n", pad - INDENT, ' ');
}
