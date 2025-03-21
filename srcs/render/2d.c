/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 11:12:43 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	render_2d(t_camera *cam, t_vector *intscts, t_img *img)
{
	t_intsct	*intsct;
	size_t		i;
	int			col;

	i = 0;
	while (i < cam->bounds->length)
		put_boundary(ft_vecindex(cam->bounds, i++), WHITE, img);
	i = 0;
	while (i < intscts->length)
	{
		intsct = ft_vecindex(intscts, i++);
		if (intsct->side == NORTH)
			col = GREEN;
		else if (intsct->side == EAST)
			col = YELLOW;
		else if (intsct->side == SOUTH)
			col = MAGENTA;
		else
			col = CYAN;
//		put_line(cam->pos, intscts[i]->pos, RED, img);
		put_point(intsct->pos, 10, col, img);
	}
	put_point(cam->pos, 15, WHITE, img);
}
