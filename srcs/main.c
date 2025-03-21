/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 14:29:15 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include "debug.h"
#include "libft.h"
#include "map.h"
#include "mlx_util.h"
#include "mlx.h"
#include "render.h"
#include "events.h"

static t_map	*temp_get_map(void)
{
	t_map		*map;

	map = new_map();
	map->player_start = (t_point){3, 3};
	ft_vecpush_consume(map->bounds, new_boundary((t_point){0, 1}, (t_point){0, 11}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){0, 11}, (t_point){1, 11}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){1, 11}, (t_point){1, 12}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){1, 12}, (t_point){11, 12}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){11, 12}, (t_point){11, 11}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){11, 11}, (t_point){12, 11}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){12, 11}, (t_point){12, 1}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){12, 1}, (t_point){11, 1}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){11, 1}, (t_point){11, 0}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){11, 0}, (t_point){1, 0}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){1, 0}, (t_point){1, 1}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){1, 1}, (t_point){0, 1}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){5, 5}, (t_point){5, 7}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){5, 7}, (t_point){7, 7}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){7, 7}, (t_point){7, 5}));
	ft_vecpush_consume(map->bounds, new_boundary((t_point){7, 5}, (t_point){5, 5}));
	map->wall_paths[NORTH] = ft_strdup("textures/north.xpm");
	map->wall_paths[EAST] = ft_strdup("textures/east.xpm");
	map->wall_paths[SOUTH] = ft_strdup("textures/south.xpm");
	map->wall_paths[WEST] = ft_strdup("textures/west.xpm");
	map->ciel_colour = WHITE;
	map->floor_colour = RED;
	return (map);
}

void	render(t_edata *data)
{
	t_vector	*intscts;

	clear_image(data->minimap);
	intscts = cast(&data->cam);
//	render_2d(&data->cam, intscts, data->minimap);
	render_3d(&data->rd, intscts, data->main_render);
	ft_vecfree(&intscts, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->main_render->img, 0, 0);
//	mlx_put_image_to_window(data->mlx, data->win, data->minimap->img,
//		0, SCREEN_Y - MINIMAP_Y);
}

int	main(void)
{
	t_edata	data;
	t_map	*map;

	data.mlx = mlx_init();
	map = temp_get_map();
	init_camera(&data.cam, map->player_start, map->start_dir, map->bounds);
	map->bounds = 0;
	init_rd(&data.rd, data.mlx, map);
	free_map(map);
	if (data.rd.walls[NORTH] == 0 || data.rd.walls[EAST] == 0
		|| data.rd.walls[SOUTH] == 0 || data.rd.walls[WEST] == 0)
	{
		mlx_destroy_display(data.mlx);
		return (1);
	}
	data.win = mlx_new_window(data.mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	data.main_render = new_image(data.mlx, SCREEN_X, SCREEN_Y);
	data.minimap = new_image(data.mlx, MINIMAP_X, MINIMAP_Y);
	data.render = render;
	mlx_hook(data.win, 17, 1L << 17, on_destroy, 0);
	mlx_hook(data.win, 2, 1L << 0, on_keydown, &data);
	render(&data);
	mlx_loop(data.mlx);
}
