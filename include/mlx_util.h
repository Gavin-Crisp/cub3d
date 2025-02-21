/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:25:17 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 15:10:08 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

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

void			put_pixel(t_img *img, int x, int y, int col);

#endif
