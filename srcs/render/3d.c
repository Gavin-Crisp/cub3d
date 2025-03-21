/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:36:58 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/19 16:55:47 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static size_t	get_rect_height(t_camera *cam, t_intsct *intsct, t_img *img)
{
	float	distance;

	distance = hypotf(cam->pos.x - intsct->pos.x, cam->pos.y - intsct->pos.y)
		* cosf(fmodf(cam->dir - intsct->angle + M_PI * 2, M_PI * 2));
	return (img->height * fminf(1, 2 * atan2f(1, 2 * distance) / cam->vfov));
}

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

void	render_3d(t_rend *rend, t_camera *cam, t_vector *intscts, t_img *img)
{
	size_t		i;
	size_t		rect_left;
	size_t		rect_width;
	size_t		wall_height;
	t_intsct	*intsct;

	rect_left = (img->width % cam->rays) / 2;
	rect_width = img->width / cam->rays;
	i = 0;
	while (i < intscts->length)
	{
		intsct = ft_vecindex(intscts, i++);
		wall_height = get_rect_height(cam, intsct, img);
		put_rect((t_pixel){rect_left, 0}, (t_pixel){rect_left + rect_width,
		(img->height - wall_height) / 2}, rend->ciel, img);
		put_rect((t_pixel){rect_left, (img->height - wall_height) / 2},
			(t_pixel){rect_left + rect_width,
			(img->height + wall_height) / 2}, get_col(intsct), img);
		put_rect((t_pixel){rect_left, (img->height + wall_height) / 2},
			(t_pixel){rect_left + rect_width, img->height},
			rend->floor, img);
		rect_left += rect_width;
	}
}
