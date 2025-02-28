/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:03:32 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 11:34:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_intsct(char *name, t_intsct *intsct, size_t indent)
{
	print_indent(indent);
	printf("t_intsct *%s: {\n", name);
	indent++;
	debug_point("pos", intsct->pos, indent);
	print_indent(indent);
	if (intsct->side == NORTH)
		printf("t_wall_side side: NORTH\n");
	if (intsct->side == EAST)
		printf("t_wall_side side: EAST\n");
	if (intsct->side == SOUTH)
		printf("t_wall_side side: SOUTH\n");
	else
		printf("t_wall_side side: WEST\n");
	indent--;
	print_indent(indent);
	printf("}\n");
}

void	debug_intscts(char *name, t_intsct **intscts, size_t indent)
{
	char	*i_name;
	size_t	i;

	print_indent(indent);
	printf("t_intsct **%s: {\n", name);
	indent++;
	i = 0;
	while (intscts[i])
	{
		i_name = ft_ultoa(i);
		debug_intsct(i_name, intscts[i++], indent);
		free(i_name);
	}
	indent--;
	print_indent(indent);
	printf("}\n");
}
