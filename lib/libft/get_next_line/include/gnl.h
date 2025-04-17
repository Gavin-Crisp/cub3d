/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:19:57 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/14 16:01:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H
# include "libft.h"

typedef struct s_file_buffer
{
	char	buf[GNL_BUFFER_SIZE];
	ssize_t	bytes_read;
}	t_file_buffer;

char	*reallocstr(char *s, size_t size);
char	*assignbuf(void);

#endif
