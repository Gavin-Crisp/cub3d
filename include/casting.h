/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:47 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 13:27:40 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H
# include <math.h>
# include "constants.h"

typedef struct s_point
{
	double	x;
	double	y;
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

t_boundary	*new_boundary(double x1, double y1, double x2, double y2);
void		free_boundary(t_boundary *);

t_ray		*new_ray(double x, double y, double degs);
void		free_ray(t_ray *);

t_point		*new_point(double x, double y);

int			has_intersection(t_boundary *bound, t_ray *ray);
t_point		*get_intersection(t_boundary *bound, t_ray *ray);

#endif
