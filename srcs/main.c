/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:24:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/12 15:22:03 by gcrisp           ###   ########.fr       */
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
	t_map		*map;

	map = new_map(M_PI_2);
	map->player = (t_point){3, 3};
	map->facing_dir = -M_PI_2;
	map->bounds = malloc(sizeof(t_boundary) * 16);
	map->bounds[0] = *new_boundary((t_point){1, 0}, (t_point){11, 0});
	map->bounds[1] = *new_boundary((t_point){11, 0}, (t_point){11, 1});
	map->bounds[2] = *new_boundary((t_point){11, 1}, (t_point){12, 1});
	map->bounds[3] = *new_boundary((t_point){12, 1}, (t_point){12, 11});
	map->bounds[4] = *new_boundary((t_point){12, 11}, (t_point){11, 11});
	map->bounds[5] = *new_boundary((t_point){11, 11}, (t_point){11, 12});
	map->bounds[6] = *new_boundary((t_point){11, 12}, (t_point){1, 12});
	map->bounds[7] = *new_boundary((t_point){1, 12}, (t_point){1, 11});
	map->bounds[8] = *new_boundary((t_point){1, 11}, (t_point){0, 11});
	map->bounds[9] = *new_boundary((t_point){0, 11}, (t_point){0, 1});
	map->bounds[10] = *new_boundary((t_point){0, 1}, (t_point){1, 1});
	map->bounds[11] = *new_boundary((t_point){1, 1}, (t_point){1, 0});
	map->bounds[12] = *new_boundary((t_point){5, 5}, (t_point){5, 7});
	map->bounds[13] = *new_boundary((t_point){5, 7}, (t_point){7, 7});
	map->bounds[14] = *new_boundary((t_point){7, 7}, (t_point){7, 5});
	map->bounds[15] = *new_boundary((t_point){7, 5}, (t_point){5, 5});
	map->num_bounds = 16;
	map->ciel_colour = WHITE;
	map->floor_colour = RED;
	return (map);
}

void	render(t_edata *data)
{
	t_intsct	**intscts;
	size_t		i;

	clear_image(data->main_render);
	clear_image(data->minimap);
	intscts = cast(data->map);
	render_3d(data->map, intscts, data->main_render);
	render_2d(data->map, intscts, data->minimap);
	i = 0;
	while (intscts[i])
		free(intscts[i++]);
	free(intscts);
	mlx_put_image_to_window(data->mlx, data->win, data->main_render->img, 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->minimap->img,
		0, SCREEN_Y - MINIMAP_Y);
}

int	main(void)
{
	t_edata	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, SCREEN_X, SCREEN_Y, "Cub3D");
	data.main_render = new_image(data.mlx, SCREEN_X, SCREEN_Y);
	data.minimap = new_image(data.mlx, MINIMAP_X, MINIMAP_Y);
	data.map = get_map();
	data.render = render;
	mlx_hook(data.win, 17, 1L << 17, on_destroy, 0);
	mlx_hook(data.win, 2, 1L << 0, on_keydown, &data);
	render(&data);
	mlx_loop(data.mlx);
}
