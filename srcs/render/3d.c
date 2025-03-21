/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 11:55:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	get_col(t_intsct *intsct)
{
	int	col;

	if (intsct->side == NORTH)
		col = GREEN;
	else if (intsct->side == EAST)
		col = YELLOW;
	else if (intsct->side == SOUTH)
		col = MAGENTA;
	else
		col = CYAN;
	return (col);
}

void	render_3d(t_rend *rend, t_vector *intscts, t_img *img)
{
	size_t		i;
	size_t		rect_left;
	size_t		rect_width;
	size_t		wall_height;
	t_intsct	*intsct;

	rect_left = (img->width % intscts->length) / 2;
	rect_width = img->width / intscts->length;
	i = 0;
	put_rect((t_pixel){0, 0}, (t_pixel){img->width, img->height / 2},
		rend->ciel, img);
	put_rect((t_pixel){0, img->height / 2},
		(t_pixel){img->width, img->height}, rend->floor, img);
	while (i < intscts->length)
	{
		intsct = ft_vecindex(intscts, i++);
		wall_height = intsct->height * img->height;
		put_rect((t_pixel){rect_left, (img->height - wall_height) / 2},
			(t_pixel){rect_left + rect_width,
			(img->height + wall_height) / 2}, get_col(intsct), img);
		rect_left += rect_width;
	}
}
