/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rays.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:25:03 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 13:51:32 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static t_point	a_to_p(t_point p, float angle)
{
	return ((t_point){p.x + cosf(angle), p.y + sinf(angle)});
}

static t_point	get_step(t_point target, t_camera *cam)
{
	t_point	target_2;

	target_2 = a_to_p(cam->pos, fmodf(cam->dir + cam->fov / 2, M_PI * 2));
	return ((t_point){(target_2.x - target.x) / cam->rays,
		(target_2.y - target.y) / cam->rays});
}

t_vector	*get_rays(t_camera *cam)
{
	t_point		target;
	t_point		step;
	t_vector	*rays;
	size_t		i;
	float		theta;

	target = a_to_p(cam->pos,
			fmodf(cam->dir - cam->fov / 2 + M_PI * 2, M_PI * 2));
	step = get_step(target, cam);
	rays = ft_vecnew_with_capacity(cam->rays, sizeof(t_ray));
	i = 0;
	while (i < cam->rays)
	{
		theta = atan2f(target.y - cam->pos.y, target.x - cam->pos.x);
		ft_vecpush(rays, &(t_ray){cam->pos, a_to_p(cam->pos, theta), theta});
		target.x += step.x;
		target.y += step.y;
		i++;
	}
	return (rays);
}
