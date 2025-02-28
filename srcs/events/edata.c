/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edata.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:30:26 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 15:42:45 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	free_edata(t_edata *data)
{
	free_map(data->map);
	free_img(data->img, data->mlx);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
}
