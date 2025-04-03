/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:35 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/03 15:30:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include "libft.h"
# include "map.h"
# include "mlx_util.h"

t_map	*parse(char	*path);

char	*parse_render_data(t_map *map, int fd);
int		parse_bounds(t_map *map, char *line, int fd);

int		parse_map_line(t_map *map, char *line, char *prev_line,
			size_t line_num);

int		is_inside(char c);
int		is_outside(char c);
int		is_player(char c);
int		is_empty(char c);

#endif
