/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:18:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 13:13:38 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_boundary(char *name, t_boundary *bound, size_t indent)
{
	int	pad;

	pad = indent * INDENT;
	printf("%*ct_boundary *%s: {\n", pad, ' ', name);
	indent++;
	debug_point("end1", bound->end1, indent);
	debug_point("end2", bound->end2, indent);
	printf("%*c}\n", pad, ' ');
}
