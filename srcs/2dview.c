#include "casting.h"
#include "constants.h"
#include "map.h"
#include "mlx.h"
#include "mlx_util.h"
#include <math.h>

void	draw_2d_view(t_map *map, void *mlx, void *mlx_win, t_img *img)
{
	t_point	**points;

	(void)mlx;
	(void)mlx_win;
	points = cast(map);
	for (size_t i = 0; points[i]; i++)
	{
		put_point(points[i], 20, trgb_to_colour(255, 255, 0, 0), img);
		put_line(map->player_pos, points[i], trgb_to_colour(122, 0, 0, 255), img);
	}
	for (size_t i = 0; i < map->num_bounds; i++)
	{
		t_boundary *bound = &map->bounds[i];
		put_line(bound->end1, bound->end2, trgb_to_colour(255, 255, 255, 255), img);
		put_point(bound->end1, 10, trgb_to_colour(255, 255, 255, 255), img);
		put_point(bound->end2, 10, trgb_to_colour(255, 255, 255, 255), img);
	}
}
