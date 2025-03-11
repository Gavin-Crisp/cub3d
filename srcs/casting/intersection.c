/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:31 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/11 14:06:38 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static float	get_denominator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1.x - bound->end2.x) * (ray->pos.y - ray->dir.y))
		- ((bound->end1.y - bound->end2.y) * (ray->pos.x - ray->dir.x)));
}

static float	get_t_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1.x - ray->pos.x) * (ray->pos.y - ray->dir.y))
		- ((bound->end1.y - ray->pos.y) * (ray->pos.x - ray->dir.x)));
}

static float	get_u_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		-1 * (((bound->end1.x - bound->end2.x) * (bound->end1.y - ray->pos.y))
			- ((bound->end1.y - bound->end2.y) * (bound->end1.x - ray->pos.x)))
	);
}

t_intsct	*get_intersection(t_ray *ray, t_boundary *bound)
{
	float		t;
	float		denom;
	float		u;
	t_wall_side	side;

	denom = get_denominator(bound, ray);
	t = get_t_numerator(bound, ray) / denom;
	u = get_u_numerator(bound, ray) / denom;
	if (0 > u)
		return (0);
	if (!(0 <= t && t <= 1))
		return (0);
	if (bound->end1.y == bound->end2.y && ray->pos.y < bound->end1.y)
		side = NORTH;
	else if (bound->end1.y == bound->end2.y)
		side = SOUTH;
	else if (ray->pos.x < bound->end1.x)
		side = WEST;
	else
		side = EAST;
	return (new_intsct(
			(t_point){bound->end1.x + t * (bound->end2.x - bound->end1.x),
			bound->end1.y + t * (bound->end2.y - bound->end1.y)}, side,
			ray->angle));
}

t_intsct	**get_intersections(
	t_ray *ray,
	t_boundary *bounds,
	size_t num_bounds)
{
	size_t		i;
	size_t		j;
	t_intsct	**out;

	i = 0;
	j = 0;
	out = ft_calloc(num_bounds + 1, sizeof(t_intsct *));
	while (i < num_bounds)
	{
		out[j] = get_intersection(ray, &bounds[i++]);
		if (out[j])
			j++;
	}
	return (out);
}
