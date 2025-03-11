/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:29 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 14:06:51 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <casting.h>

t_boundary	*new_boundary(t_point end1, t_point end2)
{
	t_boundary	*out;

	out = malloc(sizeof(t_boundary));
	out->end1 = end1;
	out->end2 = end2;
	return (out);
}

t_ray	*new_ray(t_point pos, float degs)
{
	t_ray	*out;

	out = malloc(sizeof(t_ray));
	out->pos = pos;
	out->angle = degs * DEG_TO_RAD_FACTOR;
	out->dir = (t_point){pos.x + cos(out->angle), pos.y + sin(out->angle)};
	return (out);
}

t_intsct	*new_intsct(t_point pos, t_wall_side side, float angle)
{
	t_intsct	*out;

	out = malloc(sizeof(t_intsct));
	out->pos = pos;
	out->side = side;
	out->angle = angle;
	return (out);
}
