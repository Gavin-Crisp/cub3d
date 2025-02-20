#ifndef CASTING_H
# define CASTING_H
# include <math.h>

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

t_boundary	*new_boundary(double, double, double, double);
void		free_boundary(t_boundary *);

t_ray		*new_ray(double, double, double);
void		free_ray(t_ray *);

t_point	*new_vector(double, double);

int			has_intersection(t_boundary *bound, t_ray *ray);
t_point	*get_intersection(t_boundary *bound, t_ray *ray);

#endif
