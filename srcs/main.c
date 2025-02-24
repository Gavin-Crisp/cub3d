/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 13:59:17 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "casting.h"
#include "map.h"
#include "mlx_util.h"
#include "mlx.h"
#include "libft.h"

void	draw_2d_view(t_map *map, void *mlx, void *mlx_win, t_img *img);

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
	ft_bzero(data->img.addr, ((SCREEN_Y - 1) * data->img.line_length
			+ (SCREEN_X - 1) * (data->img.bpp / 8)) - (size_t)data->img.addr);
	draw_2d_view(data->map, data->mlx, data->mlx_win, &data->img);
	return (0);
}

int	main(int argc, char const **argv)
{
	void	*mlx;
	void	*mlx_window;
	t_data	data;

	(void)argc;
	(void)argv;
	data.map = get_map();
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	mlx_loop(mlx);
}
