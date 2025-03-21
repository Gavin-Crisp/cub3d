/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 13:59:59 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static float	get_diff(t_ray *ray, t_intsct *intsct)
{
	if (ray->pos.x == intsct->pos.x)
		return (fabsf(ray->pos.y - intsct->pos.y));
	return (fabsf(ray->pos.x - intsct->pos.x));
}

t_intsct	*cast_ray(t_ray *ray, t_vector *bounds)
{
	t_intsct	*closest;
	t_intsct	*new;
	size_t		i;
	float		best_diff;
	float		diff;

	best_diff = INFINITY;
	closest = 0;
	i = 0;
	while (i < bounds->length)
	{
		new = get_intersection(ray, ft_vecindex(bounds, i++));
		if (!new)
			continue ;
		diff = get_diff(ray, new);
		if (diff < best_diff)
		{
			best_diff = diff;
			free(closest);
			closest = new;
		}
		else
			free(new);
	}
	return (closest);
}

static void	set_intsct_height(t_intsct *intsct, t_camera *cam)
{
	float	distance;

	distance = hypotf(cam->pos.x - intsct->pos.x, cam->pos.y - intsct->pos.y)
		* cosf(fmodf(cam->dir - intsct->angle + M_PI * 2, M_PI * 2));
	intsct->height = 2 * atan2f(1, 2 * distance) / cam->vfov;
}

t_vector	*cast_rays(t_vector *rays, t_camera *cam)
{
	t_vector	*closest_intscts;
	t_intsct	*closest;
	size_t		i;

	closest_intscts = ft_vecnew_with_capacity(rays->length, sizeof(t_intsct));
	i = 0;
	while (i < rays->length)
	{
		closest = cast_ray(ft_vecindex(rays, i++), cam->bounds);
		if (closest)
		{
			set_intsct_height(closest, cam);
			ft_vecpush_consume(closest_intscts, closest);
		}
	}
	return (closest_intscts);
}

t_vector	*cast(t_camera *cam)
{
	t_vector	*rays;
	t_vector	*out;

	rays = get_rays(cam);
	out = cast_rays(rays, cam);
	ft_vecfree(&rays, 0);
	return (out);
}
