/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_closest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:09:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 13:09:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"

static void	change_closest(
	t_intsct **pclosest,
	t_intsct *new_closest,
	float *pbest_diff,
	float diff)
{
	*pbest_diff = diff;
	free(*pclosest);
	*pclosest = new_closest;
}

t_intsct	*get_closest_intsct(t_ray *ray, t_vector *intscts)
{
	t_intsct	*closest;
	size_t		i;
	float		best_diff;
	float		diff;

	best_diff = INFINITY;
	closest = 0;
	i = 0;
	while (i < intscts->length)
	{
		if (ray->pos.x == ((t_intsct *)ft_vecindex(intscts, i))->pos.x)
			diff = fabsf(ray->pos.y
					- ((t_intsct *)ft_vecindex(intscts, i))->pos.y);
		else
			diff = fabsf(ray->pos.x
					- ((t_intsct *)ft_vecindex(intscts, i))->pos.x);
		if (diff < best_diff)
			change_closest(&closest, ft_vecremove(intscts, i),
				&best_diff, diff);
		else
			i++;
	}
	return (closest);
}
