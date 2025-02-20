#include <casting.h>

t_ray	*new_ray(double x, double y, double rad)
{
	t_ray	*out;

	out = malloc(sizeof(t_ray));
	out->pos = new_vector(x, y);
	out->dir = new_vector(x + cos(rad), y + sin(rad));
	return (out);
}

void	free_ray(t_ray *ray)
{
	free(ray->pos);
	free(ray->dir);
	free(ray);
}
