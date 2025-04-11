/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edata.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:26 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/11 14:59:43 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	clear_edata(t_edata *data)
{
	ft_vecfree(&data->cast.bounds, 0);
	free_img(data->rd.walls[NORTH], data->mlx);
	free_img(data->rd.walls[EAST], data->mlx);
	free_img(data->rd.walls[SOUTH], data->mlx);
	free_img(data->rd.walls[WEST], data->mlx);
	free_img(data->main_render, data->mlx);
	free_img(data->minimap, data->mlx);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
}
