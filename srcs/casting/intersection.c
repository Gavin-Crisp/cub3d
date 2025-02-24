/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:31 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 14:11:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static float	get_u_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->y - bound->end2->y)
			* (bound->end1->x - ray->pos->x))
		- ((bound->end1->x - bound->end2->x)
			* (bound->end1->y - ray->pos->y)));
}

static float	get_t_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->x - ray->pos->x)
			* (bound->end1->y - ray->pos->y))
		- ((bound->end1->y - bound->end2->y)
			* (bound->end1->x - ray->pos->x)));
}

static float	get_denominator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->x - bound->end2->x)
			* (ray->pos->y - ray->dir->y))
		- ((bound->end1->y - bound->end2->y)
			* (ray->pos->x - ray->dir->x)));
}

t_point	*get_intersection(t_ray *ray, t_boundary *bound)
{
	float	t;
	float	denom;
	float	u;

	u = get_u_numerator(bound, ray);
	if (0 > u)
		return (0);
	t = get_t_numerator(bound, ray);
	denom = get_denominator(bound, ray);
	if (!(0 <= t && t <= denom))
		return (0);
	t = t / denom;
	return (new_point(bound->end1->x + t * (bound->end2->x - bound->end1->x),
			bound->end1->y + t * (bound->end2->y - bound->end1->y)));
}

t_point	**get_intersections(t_ray *ray, t_boundary *bounds, size_t num_bounds)
{
	size_t	i;
	size_t	j;
	t_point	**out;

	i = 0;
	j = 0;
	out = ft_calloc(num_bounds + 1, sizeof(t_point *));
	while (i < num_bounds)
	{
		out[j] = get_intersection(ray, &bounds[i++]);
		if (out[j])
			j++;
	}
	return (out);
}
