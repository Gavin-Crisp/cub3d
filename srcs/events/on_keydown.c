/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keydown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:02:01 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 14:41:45 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "stdio.h"

static int	on_esc(t_edata *data)
{
	clear_edata(data);
	exit(0);
	return (1);
}

static int	on_turn(float dir, t_edata *data)
{
	data->cam.dir += dir * TURN_SPEED + M_PI * 2;
	data->cam.dir = fmodf(data->cam.dir, M_PI * 2);
	data->render(data);
	return (0);
}

static int	adjust_fov(float dir, t_edata *data)
{
	data->cam.fov += dir * FOV_INCREMENT;
	if (data->cam.fov < MIN_FOV)
		data->cam.fov = MIN_FOV;
	else if (data->cam.fov > MAX_FOV)
		data->cam.fov = MAX_FOV;
	data->cam.vfov = data->cam.fov / 16 * 9;
	data->render(data);
	return (0);
}

int	on_keydown(int key, t_edata *data)
{
	if (key == 119)
		return (on_move((t_point){0, 1}, data));
	else if (key == 97)
		return (on_move((t_point){-1, 0}, data));
	else if (key == 115)
		return (on_move((t_point){0, -1}, data));
	else if (key == 100)
		return (on_move((t_point){1, 0}, data));
	else if (key == 65361)
		on_turn(-1, data);
	else if (key == 65363)
		on_turn(1, data);
	else if (key == 65307)
		return (on_esc(data));
	else if (key == 65362)
		return (adjust_fov(1, data));
	else if (key == 65364)
		return (adjust_fov(-1, data));
	return (0);
}
