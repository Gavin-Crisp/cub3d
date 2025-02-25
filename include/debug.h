/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:31:48 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/25 14:43:33 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEBUG_H
# define DEBUG_H
# include <stdio.h>
# include "casting.h"
# include "constants.h"
# include "libft.h"
# include "map.h"

void	debug_point(char *name, t_point *point, size_t indent);
void	debug_boundary(char *name, t_boundary *bound, size_t indent);
void	debug_map(char *name, t_map *map, size_t indent);

#endif
