/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keydown.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:02:01 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/28 16:28:34 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static int	on_esc(t_edata *data)
{
	free_edata(data);
	exit(0);
	return (1);
}

static int	on_move(t_point dir, t_edata *data)
{
	t_point	move;

	move = (t_point){MOVE_SPEED, MOVE_SPEED};
	if (!dir.x)
	{
		move.x *= dir.y * cos(data->map->facing_dir * DEG_TO_RAD_FACTOR);
		move.y *= dir.y * sin(data->map->facing_dir * DEG_TO_RAD_FACTOR);
	}
	else
	{
		move.x *= dir.x * -1 * sin(data->map->facing_dir * DEG_TO_RAD_FACTOR);
		move.y *= dir.x * cos(data->map->facing_dir * DEG_TO_RAD_FACTOR);
	}
	data->map->player.x += move.x;
	data->map->player.y += move.y;
	data->render(data);
	return (0);
}

static int	on_turn(float diff, t_edata *data)
{
	data->map->facing_dir += diff;
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
		on_turn(-TURN_SPEED, data);
	else if (key == 65363)
		on_turn(TURN_SPEED, data);
	else if (key == 65307)
		return (on_esc(data));
	return (0);
}
