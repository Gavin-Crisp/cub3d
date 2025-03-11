/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:17 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/03 12:30:11 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "casting.h"
# define WHITE 0x00ffffff
# define RED 0x00ff0000
# define GREEN 0x0000ff00
# define BLUE 0x000000ff
# define YELLOW 0x00ffff00
# define MAGENTA 0x00ff00ff
# define CYAN 0x0000ffff

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bytes_pp;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_pixel
{
	size_t	x;
	size_t	y;
}	t_pixel;

t_img			*new_image(void *mlx, int width, int height);
t_img			*new_image_xpm(void *mlx, char *rel_path);
void			free_img(t_img *img, void *mlx);
void			*pixel_address(t_img *img, size_t x, size_t y);
void			clear_image(t_img *img);

t_pixel			point_to_pixel(t_img *img, t_point p);
size_t			coord_transform(float f);

int				trgb_to_colour(
					unsigned char t,
					unsigned char r,
					unsigned char g,
					unsigned char b
					);
unsigned char	colour_get_t(int col);
unsigned char	colour_get_r(int col);
unsigned char	colour_get_g(int col);
unsigned char	colour_get_b(int col);

void			put_pixel(t_pixel p, int col, t_img *img);
void			put_point(t_point p, size_t size, int col, t_img *img);
void			put_boundary(t_boundary *bound, int col, t_img *img);

void			put_line(t_pixel a, t_pixel b, int col, t_img *img);

void			put_rect(t_pixel a, t_pixel b, int col, t_img *img);
void			put_hline(t_pixel p, size_t len, int col, t_img *img);
void			put_vline(t_pixel p, size_t len, int col, t_img *img);

#endif
