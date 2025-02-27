/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:50 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 12:47:51 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static char	*make_indent(size_t indent)
{
	char	*out;
	size_t	size;

	size = ft_strlen(DEBUG_INDENT) * indent + 1;
	out = ft_calloc(sizeof(char), size);
	while (indent--)
		ft_strlcat(out, DEBUG_INDENT, size);
	return (out);
}

void	debug_point(char *name, t_point point, size_t indent)
{
	printf("%st_point %s: { x: %f, y: %f }\n",
		make_indent(indent), name, point.x, point.y);
}

void	debug_boundary(char *name, t_boundary *bound, size_t indent)
{
	char	*ind;

	ind = make_indent(indent);
	printf("%st_boundary *%s: {\n", ind, name);
	debug_point("end1", bound->end1, indent + 1);
	debug_point("end2", bound->end2, indent + 1);
	printf("%s}\n", ind);
}

void	debug_map(char *name, t_map *map, size_t indent)
{
	char	*ind;
	size_t	i;
	char	*i_name;

	ind = make_indent(indent);
	printf("%st_map *%s: {\n", ind, name);
	debug_point("player_pos", map->player, indent + 1);
	printf("%s    float facing_dir: %f\n", ind, map->facing_dir);
	printf("%s    t_boundary *bounds: {\n", ind);
	i = 0;
	indent += 2;
	while (i < map->num_bounds)
	{
		i_name = ft_ultoa((unsigned long)i);
		debug_boundary(i_name, &map->bounds[i++], indent);
		free(i_name);
	}	
	printf("%s    }\n", ind);
	printf("%s    size_t num_bounds: %zu\n",
		ind, map->num_bounds);
	printf("%s}\n", ind);
}
