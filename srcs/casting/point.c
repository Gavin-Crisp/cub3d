#include "casting.h"

t_point	*new_point(double x, double y)
{
	t_point	*out;

	out = malloc(sizeof(t_point));
	out->x = x;
	out->y = y;
	return (out);
}
