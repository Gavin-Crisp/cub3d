/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 15:21:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

t_intsct	*get_closest_intsct(t_ray *ray, t_intsct **intscts)
{
	t_intsct	*closest;
	size_t		i;
	float		best_diff;
	float		diff;

	i = 0;
	best_diff = 10000000000000.0f;
	closest = 0;
	while (intscts[i])
	{
		if (ray->pos.x == intscts[i]->pos.x)
			diff = fabsf(ray->pos.y - intscts[i]->pos.y);
		else
			diff = fabsf(ray->pos.x - intscts[i]->pos.x);
		if (diff < best_diff)
		{
			best_diff = diff;
			free(closest);
			closest = intscts[i++];
		}
		else
			free(intscts[i++]);
	}
	return (closest);
}
