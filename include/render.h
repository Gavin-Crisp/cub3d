/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:35:23 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 11:13:06 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "casting.h"
# include "map.h"
# include "mlx_util.h"
# include "math.h"

typedef struct s_rend
{
	t_img		*walls[4];
	int			ciel;
	int			floor;
}	t_rend;

void	init_rd(t_rend *rd, void *mlx, t_map *map);

void	render_2d(t_camera *cam, t_vector *intscts, t_img *img);
void	render_3d(t_rend *rd, t_camera *cam, t_vector *intscts, t_img *img);

#endif
