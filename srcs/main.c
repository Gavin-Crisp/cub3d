/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/27 13:06:06 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include "debug.h"
#include "libft.h"
#include "map.h"
#include "mlx_util.h"
#include "mlx.h"
#include "render.h"

static t_map	*get_map(void)
{
	t_boundary	*bounds;

	bounds = malloc(sizeof(t_boundary) * 4);
	bounds[0] = *new_boundary((t_point){0, 0}, (t_point){3, 0});
	bounds[1] = *new_boundary((t_point){3, 0}, (t_point){3, 3});
	bounds[2] = *new_boundary((t_point){3, 3}, (t_point){0, 3});
	bounds[3] = *new_boundary((t_point){0, 3}, (t_point){0, 0});
	return (new_map((t_point){1.5, 1.5}, bounds, 4));
}

typedef struct s_data
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_img	img;
}	t_data;

int	update_pos(int x, int y, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	data->map->player.x = (double)(x / SCREEN_X);
	data->map->player.y = (double)(y / SCREEN_Y);
	clear_image(&data->img);
	render_2d(data->map, &data->img);
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*mlx_window;
	t_data	data;

	data.map = get_map();
	debug_map("test_map", data.map, 0);
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	mlx_loop(mlx);
}
