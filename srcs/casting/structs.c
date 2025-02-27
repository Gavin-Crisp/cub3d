/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:29 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 12:51:26 by gcrisp           ###   ########.fr       */
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
	float	rads;

	out = malloc(sizeof(t_ray));
	out->pos = pos;
	rads = degs * DEG_TO_RAD_FACTOR;
	out->dir = (t_point){pos.x + cos(rads), pos.y + sin(rads)};
	return (out);
}

t_intsct	*new_intsct(t_point pos, t_wall_side side)
{
	t_intsct	*out;

	out = malloc(sizeof(t_intsct));
	out->pos = pos;
	out->side = side;
	return (out);
}
