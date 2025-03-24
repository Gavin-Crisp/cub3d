/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:16:33 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/24 15:10:22 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_comp(char *str)
{
	int	out;

	if (!ft_stris_numeric(str))
		return (-1);
	out = ft_atoi(str);
	free(str);
	if (out > 255)
		out = -1;
	return (out);
}

int	parse_colour_line(t_map *map, char *line)
{
	int		*var;
	int		rgb[3];
	char	**str_rgb;
	size_t	len;

	len = ft_strlen(line);
	if (len < 7 || line[1] != ' ' || ft_strcount(line, ',') != 2)
		return (1);
	if (line[len - 1] == '\n')
		line[len - 1] = 0;
	if (line[0] == 'C')
		var = &map->ciel_colour;
	else
		var = &map->floor_colour;
	if (colour_get_t(*var) == 0)
		return (1);
	str_rgb = ft_split(&line[2], ',');
	rgb[0] = parse_comp(str_rgb[0]);
	rgb[1] = parse_comp(str_rgb[1]);
	rgb[2] = parse_comp(str_rgb[2]);
	free(str_rgb);
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (1);
	*var = trgb_to_colour(0, rgb[0], rgb[1], rgb[2]);
	return (0);
}
