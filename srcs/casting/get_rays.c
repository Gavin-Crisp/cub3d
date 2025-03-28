/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:25:03 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 13:13:05 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static t_point	a_to_p(t_point p, float angle)
{
	return ((t_point){p.x + cosf(angle), p.y + sinf(angle)});
}

static t_point	get_step(t_point target, t_cast *cast)
{
	t_point	target_2;

	target_2 = a_to_p(cast->pos, fmodf(cast->dir + cast->fov / 2, M_PI * 2));
	return ((t_point){(target_2.x - target.x) / cast->rays,
		(target_2.y - target.y) / cast->rays});
}

t_vector	*get_rays(t_cast *cast)
{
	t_point		target;
	t_point		step;
	t_vector	*rays;
	size_t		i;
	float		theta;

	target = a_to_p(cast->pos,
			fmodf(cast->dir - cast->fov / 2 + M_PI * 2, M_PI * 2));
	step = get_step(target, cast);
	rays = ft_vecnew_with_capacity(cast->rays, sizeof(t_ray));
	i = 0;
	while (i < cast->rays)
	{
		theta = atan2f(target.y - cast->pos.y, target.x - cast->pos.x);
		ft_vecpush(rays, &(t_ray){cast->pos, a_to_p(cast->pos, theta), theta});
		target.x += step.x;
		target.y += step.y;
		i++;
	}
	return (rays);
}
