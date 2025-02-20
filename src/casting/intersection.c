#include "casting.h"

static double	get_u_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->y - bound->end2->y)
			* (bound->end1->x - ray->pos->x))
		- ((bound->end1->x - bound->end2->x)
			* (bound->end1->y - ray->pos->y)));
}

static double	get_t_numerator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->x - ray->pos->x)
			* (bound->end1->y - ray->pos->y))
		- ((bound->end1->y - bound->end2->y)
				* (bound->end1->x - ray->pos->x)));
}

static double	get_denominator(t_boundary *bound, t_ray *ray)
{
	return (
		((bound->end1->x - bound->end2->x)
			* (ray->pos->y - ray->dir->y))
		- ((bound->end1->y - bound->end2->y)
			* (ray->pos->x - ray->dir->x)));
}

int	has_intersection(t_boundary *bound, t_ray *ray)
{
	double	t;
	double	denom;
	double	u;

	u = get_u_numerator(bound, ray);
	if (u <= 0)
		return (0);
	t = get_t_numerator(bound, ray);
	denom = get_denominator(bound, ray);
	if (t < 0 || t > denom)
		return (0);
	return (1);
}

t_point	*get_intersection(t_boundary *bound, t_ray *ray)
{
	double	t;
	double	denom;
	double	u;

	u = get_u_numerator(bound, ray);
	if (u <= 0)
		return (0);
	t = get_t_numerator(bound, ray);
	denom = get_denominator(bound, ray);
	if (t < 0 || t > denom)
		return (0);
	t = t / denom;
	return (new_vector(bound->end1->x + t * (bound->end2->x - bound->end1->x),
			bound->end1->y + t * (bound->end2->y - bound->end1->y)));
}
