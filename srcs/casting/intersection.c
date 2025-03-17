/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:31 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/13 15:30:40 by gcrisp           ###   ########.fr       */
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
	if (!(0 <= u))
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
			bound->end1.y + t * (bound->end2.y - bound->end1.y)}, ray->angle,
		side, fmodf(t * b_length(bound), 1)));
}

t_vector	*get_intersections(t_ray *ray, t_vector *bounds)
{
	size_t		i;
	t_vector	*out;
	t_intsct	*intsct;

	i = 0;
	out = ft_vecnew(sizeof(t_intsct));
	while (i < bounds->length)
	{
		intsct = get_intersection(ray, ft_vecindex(bounds, i++));
		if (intsct)
			ft_vecpush(out, intsct);
		free(intsct);
	}
	return (out);
}
