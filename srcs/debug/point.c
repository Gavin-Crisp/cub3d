/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 11:01:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 11:02:47 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "debug.h"

void	debug_point(char *name, t_point point, size_t indent)
{
	print_indent(indent);
	printf("t_point %s: { x: %f, y: %f }\n", name, point.x, point.y);
}
