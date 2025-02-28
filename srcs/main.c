/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 15:56:47 by gcrisp           ###   ########.fr       */
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

static t_map	*get_map(void)
{
	t_boundary	*bounds;

	bounds = malloc(sizeof(t_boundary) * 4);
	bounds[0] = *new_boundary((t_point){0, 0}, (t_point){6, 0});
	bounds[1] = *new_boundary((t_point){6, 0}, (t_point){6, 6});
	bounds[2] = *new_boundary((t_point){6, 6}, (t_point){0, 6});
	bounds[3] = *new_boundary((t_point){0, 6}, (t_point){0, 0});
	return (new_map((t_point){3, 3}, bounds, 4));
}

void	render(t_edata *data)
{
	clear_image(data->img);
	render_2d(data->map, data->img);
	mlx_put_image_to_window(data->mlx, data->win, data->img->img, 0, 0);
}

int	main(void)
{
	t_edata	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	data.img = new_image(data.mlx, SCREEN_X, SCREEN_Y);
	data.map = get_map();
	data.render = render;
	mlx_hook(data.win, 17, 1L << 17, on_destroy, 0);
	mlx_hook(data.win, 2, 1L << 0, on_keydown, &data);
	render(&data);
	mlx_loop(data.mlx);
}
