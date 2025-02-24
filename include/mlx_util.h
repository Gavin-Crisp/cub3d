/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:17 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 15:09:55 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H
# include <stddef.h>
# define WHITE 0xffffffff
# define RED 0xffff0000
# define GREEN 0xff00ff00
# define BLUE 0xff0000ff

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

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

#endif
