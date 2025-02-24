/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:12:59 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:31:57 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clearbuf(char buf[BUFFER_SIZE])
{
	size_t	i;

	if (!buf)
		return ;
	i = 0;
	while (i < GNL_BUFFER_SIZE)
		buf[i++] = 0;
}

void	cleanbuf(char buf[BUFFER_SIZE])
{
	size_t	i;
	size_t	j;

	if (!buf)
		return ;
	i = 0;
	while (i < GNL_BUFFER_SIZE && buf[i] && buf[i] != '\n')
		buf[i++] = 0;
	if (i < GNL_BUFFER_SIZE && buf[i])
		buf[i++] = 0;
	j = 0;
	while (i < GNL_BUFFER_SIZE && buf[i])
	{
		buf[j++] = buf[i];
		buf[i++] = 0;
	}
}

char	*addbuf(char *dst, char buf[BUFFER_SIZE])
{
	size_t	bl;
	size_t	dl;
	size_t	i;

	bl = 0;
	while (bl < GNL_BUFFER_SIZE && buf[bl] && buf[bl] != '\n')
		bl++;
	if (bl < GNL_BUFFER_SIZE && buf[bl])
		bl++;
	if (bl == 0)
		return (dst);
	dl = ft_strlen(dst);
	dst = reallocstr(dst, bl + dl + 1);
	if (!dst)
		return (0);
	i = -1;
	while (++i < bl)
		dst[dl + i] = buf[i];
	return (dst);
}

char	*runloop(int fd, char *out, char buf[BUFFER_SIZE])
{
	int	bytesread;

	if (!out)
		return (0);
	out[0] = 0;
	bytesread = 1;
	out = addbuf(out, buf);
	while (!ft_strchr(out, '\n') && bytesread)
	{
		cleanbuf(buf);
		if (!out)
			return (0);
		bytesread = read(fd, buf, GNL_BUFFER_SIZE);
		out = addbuf(out, buf);
	}
	cleanbuf(buf);
	return (out);
}

char	*get_next_line(int fd)
{
	static char	*buffers[4096];
	char		*out;

	if (read(fd, 0, 0) == -1)
	{
		clearbuf(buffers[fd]);
		return (0);
	}
	if (!buffers[fd])
		buffers[fd] = assignbuf();
	if (!buffers[fd])
		return (0);
	out = malloc(1);
	out = runloop(fd, out, buffers[fd]);
	if (!out)
		return (0);
	if (!out[0])
	{
		free(buffers[fd]);
		buffers[fd] = 0;
		free(out);
		return (0);
	}
	return (out);
}
