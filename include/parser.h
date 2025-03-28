/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:35 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 12:57:13 by gcrisp           ###   ########.fr       */
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

#endif
