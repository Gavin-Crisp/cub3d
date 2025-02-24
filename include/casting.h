/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:47 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 14:19:15 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H
# include <math.h>
# include <stdlib.h>
# include "libft.h"
# include "constants.h"

typedef struct s_point
{
	float	x;
	float	y;
}	t_point;

typedef struct s_boundary
{
	t_point	*end1;
	t_point	*end2;
}	t_boundary;

typedef struct s_ray
{
	t_point	*pos;
	t_point	*dir;
}	t_ray;

t_boundary	*new_boundary(float x1, float y1, float x2, float y2);
void		free_boundary(t_boundary *bound);
void		free_boundary_array(t_boundary *bounds, size_t num_bounds);

t_ray		*new_ray(float x, float y, float degs);
void		free_ray(t_ray *ray);

t_point		*new_point(float x, float y);

t_point		*get_intersection(t_ray *ray, t_boundary *bound);
t_point		**get_intersections(
				t_ray *ray,
				t_boundary *bounds,
				size_t num_bounds);

t_point		*get_closest_point(t_ray *ray, t_point **points);

#endif
