/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:22:08 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/26 14:51:55 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

static t_ray	get_ray(t_point dir, t_edata *data)
{
	t_ray	move;

	move = (t_ray) {data->cam.pos, (t_point) {0, 0}, data->cam.dir};
	if (dir.x == 1)
	{
		move.dir.x = MOVE_SPEED * (-1 * sin(data->cam.dir)) + move.pos.x;
		move.dir.y = MOVE_SPEED * (cos(data->cam.dir)) + move.pos.y;
	}
	else if (dir.x == -1)
	{
		move.dir.x = -1 * MOVE_SPEED * (-1 * sin(data->cam.dir)) + move.pos.x;
		move.dir.y = -1 * MOVE_SPEED * (cos(data->cam.dir)) + move.pos.y;
	}
	else if (dir.y == 1)
	{
		move.dir.x = MOVE_SPEED * cos(data->cam.dir) + move.pos.x;
		move.dir.y = MOVE_SPEED * sin(data->cam.dir) + move.pos.y;
	}
	else
	{
		move.dir.x = -1 * MOVE_SPEED * cos(data->cam.dir) + move.pos.x;
		move.dir.y = -1 * MOVE_SPEED * sin(data->cam.dir) + move.pos.y;
	}
	return (move);
}

int	on_move(t_point dir, t_edata *data)
{
	t_ray		move;
	t_intsct	*intsct;

	move = get_ray(dir, data);
	intsct = cast_ray(&move, data->cam.bounds);
	if (!(intsct && (fabsf(intsct->pos.x - data->cam.pos.x)
		< fabsf(move.dir.x - data->cam.pos.x)
		|| fabsf(intsct->pos.y - data->cam.pos.y)
		< fabsf(move.dir.y - data->cam.pos.y))))
	{
		data->cam.pos.x = move.dir.x;
		data->cam.pos.y = move.dir.y;
	}
	free(intsct);
	data->render(data);
	return (0);
}
