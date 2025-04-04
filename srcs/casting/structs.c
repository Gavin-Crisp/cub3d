/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:29 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 15:43:18 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

t_boundary	*new_boundary(t_point end1, t_point end2)
{
	t_boundary	*out;

	out = malloc(sizeof(t_boundary));
	out->end1 = end1;
	out->end2 = end2;
	return (out);
}

float	b_length(t_boundary *bound)
{
	if (bound->end1.x == bound->end2.x)
		return (fabsf(bound->end1.y - bound->end2.y));
	return (fabsf(bound->end1.x - bound->end2.x));
}

t_ray	*new_ray(t_point pos, float angle)
{
	t_ray	*out;

	out = malloc(sizeof(t_ray));
	out->pos = pos;
	out->angle = angle;
	out->dir = (t_point){pos.x + cos(out->angle), pos.y + sin(out->angle)};
	return (out);
}

t_intsct	*new_intsct(t_point pos, float angle, t_wall_side side, float uv)
{
	t_intsct	*out;

	out = malloc(sizeof(t_intsct));
	out->pos = pos;
	out->angle = angle;
	out->side = side;
	out->uv = uv;
	out->height = 0;
	return (out);
}

void	init_cast(t_cast *cast, t_point pos, float dir, t_vector *bounds)
{
	cast->pos = pos;
	cast->dir = dir;
	cast->fov = INIT_FOV;
	cast->vfov = INIT_FOV / 16 * 9;
	cast->rays = INIT_RAYS;
	cast->bounds = bounds;
}
