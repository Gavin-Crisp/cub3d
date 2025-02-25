/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 12:35:23 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 12:41:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H
# include "casting.h"
# include "map.h"
# include "mlx_util.h"

void	render_2d(t_map *map, t_img *img);
void	render_3d(t_map *map, t_img *img);

#endif
