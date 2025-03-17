/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edata.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:26 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/13 15:33:07 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	free_edata(t_edata *data)
{
	free_map(data->map);
	free_img(data->main_render, data->mlx);
	free_img(data->minimap, data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}
