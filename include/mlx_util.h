/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:17 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 16:15:00 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H
# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# define WHITE 0xffffffff
# define RED 0xffff0000
# define GREEN 0xff00ff00
# define BLUE 0xff0000ff

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

t_img			*new_image(void *mlx, int width, int height);
t_img			*new_image_xpm(void *mlx, char *rel_path);
void			*pixel_address(t_img *img, size_t x, size_t y);
void			clear_image(t_img *img);

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

void			put_pixel(t_img *img, size_t x, size_t y, int col);
void			put_point(t_point *p, size_t size, int col, t_img *img);
void			put_line(t_point *a, t_point *b, int col, t_img *img);

#endif
