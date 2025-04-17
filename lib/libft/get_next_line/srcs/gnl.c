/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:12:59 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/17 12:17:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "gnl.h"

static char	*copy_buffer(t_file_buffer *buffer)
{
	char	*new;
	ssize_t	line_len;
	ssize_t	i;

	line_len = 0;
	while (line_len < buffer->bytes_read && buffer->buf[line_len] != '\n')
		line_len++;
	if (line_len < buffer->bytes_read)
		line_len++;
	new = ft_strndup(buffer->buf, line_len);
	buffer->bytes_read -= line_len;
	i = 0;
	while (i < buffer->bytes_read)
	{
		buffer->buf[i] = buffer->buf[line_len + i];
		i++;
	}
	return (new);
}

static char	*append_buffer(char *old, t_file_buffer *buffer)
{
	char	*new;
	ssize_t	new_len;
	ssize_t	line_len;
	ssize_t	i;

	if (!old)
		return (copy_buffer(buffer));
	line_len = 0;
	while (line_len < buffer->bytes_read && buffer->buf[line_len] != '\n')
		line_len++;
	if (line_len < buffer->bytes_read)
		line_len++;
	new_len = ft_strlen(old) + line_len + 1;
	new = malloc(new_len);
	ft_strlcpy(new, old, new_len);
	free(old);
	ft_strlcat(new, buffer->buf, new_len);
	buffer->bytes_read -= line_len;
	i = 0;
	while (i < buffer->bytes_read)
	{
		buffer->buf[i] = buffer->buf[line_len + i];
		i++;
	}
	return (new);
}

char	*get_next_line(int fd)
{
	static t_file_buffer	buffers[4096];
	char					*out;

	out = 0;
	if (buffers[fd].bytes_read)
		out = copy_buffer(&buffers[fd]);
	while (!buffers[fd].bytes_read)
	{
		buffers[fd].bytes_read = read(fd, buffers[fd].buf, GNL_BUFFER_SIZE);
		if (buffers[fd].bytes_read == -1)
		{
			free(out);
			return (0);
		}
		if (buffers[fd].bytes_read == 0)
			return (out);
		out = append_buffer(out, &buffers[fd]);
	}
	return (out);
}
