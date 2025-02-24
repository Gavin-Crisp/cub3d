#include "casting.h"
#include "constants.h"
#include "map.h"
#include "mlx.h"
#include "mlx_util.h"
#include <math.h>

t_point	*snap_to_grid(t_point *p)
{
	return (new_point(round(p->x - 0.25), round(p->y - 0.225)));
}

void	draw_point(t_point *p, int radius, int colour, t_img *img)
{
	p = snap_to_grid(p);
	radius++;
	while (--radius)
	{
		int r = radius;
		int	x = -r;
		int	y = 0;
		int error = 2 - 2 * r;
		do
		{
			put_pixel(img, (int)p->x - x, (int)p->y + y, colour);
			put_pixel(img, (int)p->x - y, (int)p->y - x, colour);
			put_pixel(img, (int)p->x + x, (int)p->y - y, colour);
			put_pixel(img, (int)p->x + y, (int)p->y + x, colour);
			r = error;
			if (r <= y)
				error += ++y * 2 + 1;
			if (r > x || error > y)
				error += ++x * 2 + 1;
		} while (x < 0);
	}
	free(p);
}

void	draw_line(t_point *a, t_point *b, int colour, t_img *img)
{
	a = snap_to_grid(a);
	b = snap_to_grid(b);
	int dx = abs((int)a->x - (int)b->x);
	int dy = abs((int)a->y - (int)b->y);
	int step_x;
	if ((int)a->x < (int)b->x)
		step_x = 1;
	else
		step_x = -1;
	int step_y;
	if ((int)a->y < (int)b->y)
		step_y = 1;
	else
		step_y = -1;
	int error = dx + dy;
	int err2;
	while (1)
	{
		put_pixel(img, (int)a->x, (int)a->y, colour);
		if ((int)a->x == (int)b->x && (int)a->y == (int)b->y)
			break ;
		err2 = 2 * error;
		if (err2 >= dy)
		{
			error += dy;
			a->x += step_x;
		}
		if (err2 <= dx)
		{
			error += dx;
			a->y += step_y;
		}
	}
	free(a);
	free(b);
}

void	draw_2d_view(t_map *map, void *mlx, void *mlx_win, t_img *img)
{
	t_point	**points;

	(void)mlx;
	(void)mlx_win;
	points = cast(map);
	for (size_t i = 0; points[i]; i++)
	{
		draw_point(points[i], 20, trgb_to_colour(255, 255, 0, 0), img);
		draw_line(map->player_pos, points[i], trgb_to_colour(122, 0, 0, 255), img);
	}
	for (size_t i = 0; i < map->num_bounds; i++)
	{
		t_boundary *bound = &map->bounds[i];
		draw_line(bound->end1, bound->end2, trgb_to_colour(255, 255, 255, 255), img);
		draw_point(bound->end1, 10, trgb_to_colour(255, 255, 255, 255), img);
		draw_point(bound->end2, 10, trgb_to_colour(255, 255, 255, 255), img);
	}
}
