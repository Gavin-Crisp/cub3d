/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 13:19:38 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

t_point	*get_closest_point(t_ray *ray, t_point **points)
{
	t_point	*closest;
	size_t	i;
	float	best_diff;
	float	diff;

	i = 0;
	best_diff = 100000000000000;
	while (points[i])
	{
		if (ray->pos->x == points[i]->x)
			diff = abs(ray->pos->y - points[i]->y);
		else
			diff = abs(ray->pos->x - points[i]->y);
		if (diff < best_diff)
		{
			best_diff = diff;
			free(closest);
			closest = points[i++];
		}
		else
			free(points[i++]);
	}
	return (closest);
}
