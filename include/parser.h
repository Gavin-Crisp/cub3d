/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 11:23:35 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 15:29:38 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H
# include <fcntl.h>
# include "libft.h"
# include "map.h"
# include "mlx_util.h"

t_map	*parse(char	*path);

int		parse_map_line(t_map *map, char *line);
int		parse_texture_line(t_map *map, char *line);
int		parse_colour_line(t_map *map, char *line);

#endif
