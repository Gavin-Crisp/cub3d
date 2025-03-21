/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intsct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:03:32 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 13:13:53 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_intsct(char *name, t_intsct *intsct, size_t indent)
{
	int	pad;

	pad = indent * INDENT;
	printf("%*ct_intsct *%s: {\n", pad, ' ', name);
	pad += INDENT;
	debug_point("pos", intsct->pos, indent + 1);
	printf("float angle: %f\n", intsct->angle);
	if (intsct->side == NORTH)
		printf("%*ct_wall_side side: NORTH\n", pad, ' ');
	else if (intsct->side == EAST)
		printf("%*ct_wall_side side: EAST\n", pad, ' ');
	else if (intsct->side == SOUTH)
		printf("%*ct_wall_side side: SOUTH\n", pad, ' ');
	else
		printf("%*ct_wall_side side: WEST\n", pad, ' ');
	printf("%*cfloat uv: %f\n", pad, ' ', intsct->uv);
	printf("%*c}\n", pad - INDENT, ' ');
}
