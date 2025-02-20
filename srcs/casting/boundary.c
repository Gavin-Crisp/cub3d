#include <casting.h>

t_boundary	*new_boundary(double x1, double y1, double x2, double y2)
{
	t_boundary	*out;

	out = malloc(sizeof(t_boundary));
	out->end1 = new_point(x1, y1);
	out->end2 = new_point(x2, y2);
	return (out);
}

void	free_boundary(t_boundary *bound)
{
	free(bound->end1);
	free(bound->end2);
	free(bound);
}
