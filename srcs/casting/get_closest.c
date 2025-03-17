/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 15:49:13 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static float	get_diff(t_ray *ray, t_intsct *intsct)
{
	if (ray->pos.x == intsct->pos.x)
		return (fabsf(ray->pos.y - intsct->pos.y));
	return (fabsf(ray->pos.x - intsct->pos.x));
}

t_intsct	*get_closest_intsct(t_ray *ray, t_vector *bounds)
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
