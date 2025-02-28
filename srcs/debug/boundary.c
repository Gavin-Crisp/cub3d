/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:18:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 11:29:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_boundary(char *name, t_boundary *bound, size_t indent)
{
	print_indent(indent);
	printf("t_boundary *%s: {\n", name);
	indent++;
	debug_point("end1", bound->end1, indent);
	debug_point("end2", bound->end2, indent);
	indent--;
	print_indent(indent);
	printf("}\n");
}
