/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 11:50:12 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/28 13:05:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	parse_texture(t_map *map, char **pline)
{
	char	**path;

	if (ft_strncmp(*pline, "NO ", 3) == 0)
		path = &map->wall_paths[NORTH];
	else if (ft_strncmp(*pline, "EA ", 3) == 0)
		path = &map->wall_paths[EAST];
	else if (ft_strncmp(*pline, "SO ", 3) == 0)
		path = &map->wall_paths[SOUTH];
	else if (ft_strncmp(*pline, "WE ", 3) == 0)
		path = &map->wall_paths[WEST];
	else
		return (0);
	if (*path)
	{
		free(*pline);
		return (1);
	}
	*path = ft_strtrim(*pline + 3, " \n");
	free(*pline);
	*pline = 0;
	return (0);
}

static int	str_to_val(char *str)
{
	int	out;

	if (!ft_stris_numeric(str))
		return (-1);
	out = ft_atoi(str);
	free(str);
	if (out > 255)
		return (-1);
	return (out);
}

static int	vals_to_col(char *str)
{
	char	**vals;
	int		rgb[3];

	vals = ft_split(str, ',');
	free(str);
	rgb[0] = str_to_val(vals[0]);
	rgb[1] = str_to_val(vals[1]);
	rgb[2] = str_to_val(vals[2]);
	free(vals);
	if (rgb[0] < 0 || rgb[1] < 0 || rgb[2] < 0)
		return (-1);
	return (trgb_to_colour(0, rgb[0], rgb[1], rgb[2]));
}

static int	parse_colour(t_map *map, char **pline)
{
	int	*colour;

	if (ft_strncmp(*pline, "C ", 2) == 0)
		colour = &map->ciel_colour;
	else if (ft_strncmp(*pline, "F ", 2) == 0)
		colour = &map->floor_colour;
	else
		return (0);
	if (colour_get_t(*colour) != 0xff || ft_strcount(*pline, ',') != 2)
	{
		free(*pline);
		return (0);
	}
	*colour = vals_to_col(ft_strtrim(*pline + 2, " \n"));
	free(*pline);
	if (*colour < 0)
		return (1);
	*pline = 0;
	return (0);
}

char	*parse_render_data(t_map *map, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		else if (parse_texture(map, &line))
			return (0);
		else if (line && parse_colour(map, &line))
			return (0);
		else if (line && line[0] == '\n')
			free(line);
		else if (line && (line[0] == '1' || ft_isspace(line[0])))
			return (line);
		else if (line)
		{
			free(line);
			return (0);
		}
	}
}
