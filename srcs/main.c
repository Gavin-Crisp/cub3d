/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 14:44:25 by gcrisp           ###   ########.fr       */
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
	t_boundary	*bounds = malloc(sizeof(t_boundary) * 4);
	bounds[0] = *new_boundary(0, 0, 3, 0);
	bounds[1] = *new_boundary(3, 0, 3, 3);
	bounds[2] = *new_boundary(3, 3, 0, 3);
	bounds[3] = *new_boundary(0, 3, 0, 0);
	return (new_map(1.5, 1.5, bounds, 4));
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
	data->map->player_pos->x = (double)(x / SCREEN_X);
	data->map->player_pos->y = (double)(y / SCREEN_Y);
	clear_image(&data->img);
	render_2d(data->map,&data->img);
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
