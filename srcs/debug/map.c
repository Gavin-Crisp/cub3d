/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:38:50 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 15:06:49 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

static void	p_bounds(t_map *map, size_t indent)
{
	char	*i_name;
	size_t	i;

	print_indent(indent);
	printf("t_vector<t_boundary> *bounds: {\n");
	indent++;
	i = 0;
	while (i < map->bounds->length)
	{
		i_name = ft_ultoa(i);
		debug_boundary(i_name, ft_vecindex(map->bounds, i++), indent);
		free(i_name);
	}
	indent--;
	print_indent(indent);
	printf("}\n");
}

void	debug_map(char *name, t_map *map, size_t indent)
{
	print_indent(indent);
	printf("t_map *%s: {\n", name);
	indent++;
	debug_point("player_pos", map->player, indent);
	print_indent(indent);
	printf("float facing_dir: %f\n", map->facing_dir);
	p_bounds(map, indent);
	indent--;
	print_indent(indent);
	printf("}\n");
}
