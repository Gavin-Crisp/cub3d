/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 14:45:18 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:53:36 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H
# include "mlx.h"
# include "mlx_util.h"
# include "map.h"

typedef struct s_edata	t_edata;
struct s_edata
{
	void	*mlx;
	void	*win;
	t_img	*main_render;
	t_img	*minimap;
	t_map	*map;
	void	(*render)(t_edata *data);
};

void	free_edata(t_edata *data);

int		on_destroy(t_edata *param);
int		on_keydown(int key, t_edata *data);

#endif
