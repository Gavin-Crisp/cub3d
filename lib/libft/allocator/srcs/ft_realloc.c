/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:09 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:25:10 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

static void	*contract_alloc(t_dllist *chunks, size_t new_size)
{
	size_t	difference;

	difference = ((t_chunk *)chunks->data)->size - new_size;
	((t_chunk *)chunks->data)->size = new_size;
	((t_chunk *)chunks->next->data)->size += difference;
	((t_chunk *)chunks->next->data)->start
		= ((t_chunk *)chunks->next->data)->start - difference;
	return (((t_chunk *)chunks->data)->start);
}

static void	*expand_alloc(t_dllist *chunks, size_t new_size)
{
	size_t	difference;

	difference = new_size - ((t_chunk *)chunks->data)->size;
	((t_chunk *)chunks->data)->size = new_size;
	((t_chunk *)chunks->next->data)->size -= difference;
	((t_chunk *)chunks->next->data)->start
		= ((t_chunk *)chunks->next->data)->start + difference;
	return (((t_chunk *)chunks->data)->start);
}

static void	*move_alloc(t_dllist *chunks, size_t new_size)
{
	void	*out;

	out = ft_malloc(new_size);
	ft_memcpy(out, ((t_chunk *)chunks->data)->start,
		((t_chunk *) chunks->data)->size);
	free_chunk(&chunks);
	return (out);
}

void	*ft_realloc(void *ptr, size_t new_size)
{
	t_dllist	*chunks;

	if (!ptr)
		return (ft_malloc(new_size));
	if (!new_size)
	{
		ft_free(ptr);
		return (0);
	}
	chunks = find_chunk(ptr);
	if (!chunks || ((t_chunk *)chunks->data)->is_free)
		return (ptr);
	if (new_size == ((t_chunk *)chunks->data)->size)
		return (ptr);
	if (new_size < ((t_chunk *)chunks->data)->size)
		return (contract_alloc(ptr, new_size));
	if (((t_chunk *)chunks->data)->size + ((t_chunk *)chunks->next->data)->size
		<= new_size)
		return (expand_alloc(chunks, new_size));
	return (move_alloc(chunks, new_size));
}
