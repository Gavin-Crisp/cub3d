/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:45 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 15:34:37 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <casting.h>

t_ray	*new_ray(float x, float y, float degs)
{
	t_ray	*out;
	float	rads;

	out = malloc(sizeof(t_ray));
	out->pos = new_point(x, y);
	rads = degs * DEG_TO_RAD_FACTOR;
	out->dir = new_point(x + cos(rads), y + sin(rads));
	return (out);
}

void	free_ray(t_ray *ray)
{
	if (!ray)
		return ;
	free(ray->pos);
	free(ray->dir);
	free(ray);
}
