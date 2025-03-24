/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 13:53:59 by gcrisp           ###   ########.fr       */
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
#include "parser.h"

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

//static int	init_data(t_edata *data, char *map_file)
//{
//	t_map	*map;
//
//	map = parse(map_file);
//	if (!map)
//		return (2);
//	data->mlx = mlx_init();
//	map->bounds = 0;
//	init_rd(&data->rd, data->mlx, map);
//	free_map(map);
//	if (data->rd.walls[NORTH] == 0 || data->rd.walls[EAST] == 0
//		|| data->rd.walls[SOUTH] == 0 || data->rd.walls[WEST] == 0)
//	{
//		mlx_destroy_display(data->mlx);
//		return (1);
//	}
//	init_camera(&data->cam, map->player_start, map->start_dir, map->bounds);
//	data->win = mlx_new_window(data->mlx, SCREEN_X, SCREEN_Y, "Cub3D");
//	data->main_render = new_image(data->mlx, SCREEN_X, SCREEN_Y);
//	data->minimap = new_image(data->mlx, MINIMAP_X, MINIMAP_Y);
//	data->render = render;
//	return (0);
//}

int	main(int argc, char *argv[])
{
//	t_edata	data;
	t_map	*map;
//	int		init_ret;

	if (argc != 2)
		return (printf("usage: %s <map file>\n", argv[0]));
	map = parse(argv[1]);
	if (!map)
		return (1);
	debug_map("map", map, 1);
	free_map(map);
//	init_ret = init_data(&data, argv[1]);
//	if (init_ret)
//	{
//		printf("Error:\n");
//		if (init_ret == 1)
//			printf("%s: Could not parse all textures\n", argv[0])
//		else
//			perror(argv[0]);
//		return (1);
//	}
//	mlx_hook(data.win, 17, 1L << 17, on_destroy, 0);
//	mlx_hook(data.win, 2, 1L << 0, on_keydown, &data);
//	render(&data);
//	mlx_loop(data.mlx);
}
