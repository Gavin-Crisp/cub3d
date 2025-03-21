/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:45:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/21 13:51:12 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "mlx.h"
# include "mlx_util.h"
# include "map.h"
# include "render.h"

typedef struct s_edata	t_edata;
struct s_edata
{
	void		*mlx;
	void		*win;
	t_img		*main_render;
	t_img		*minimap;
	t_rend		rd;
	t_camera	cam;
	void		(*render)(t_edata *data);
};

void	clear_edata(t_edata *data);

int		on_destroy(t_edata *param);
int		on_keydown(int key, t_edata *data);

#endif
