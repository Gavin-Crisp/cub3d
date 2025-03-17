/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:26:47 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/17 15:34:19 by gcrisp           ###   ########.fr       */
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
	t_point	end1;
	t_point	end2;
}	t_boundary;

typedef struct s_ray
{
	t_point	pos;
	t_point	dir;
	float	angle;
}	t_ray;

typedef enum e_wall_side
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_wall_side;

typedef struct s_intsct
{
	t_point		pos;
	float		angle;
	t_wall_side	side;
	float		uv;
}	t_intsct;

t_boundary	*new_boundary(t_point end1, t_point end2);
float		b_length(t_boundary *bound);
t_ray		*new_ray(t_point pos, float angle);
t_intsct	*new_intsct(t_point pos, float angle, t_wall_side side, float uv);

t_intsct	*get_intersection(t_ray *ray, t_boundary *bound);

t_intsct	*get_closest_intsct(t_ray *ray, t_vector *bounds);

#endif
