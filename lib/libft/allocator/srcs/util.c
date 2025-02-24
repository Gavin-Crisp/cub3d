/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:24:14 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:24:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "allocator.h"

int	cmp_ptrs(void *vchunk, void *ptr)
{
	return (((t_chunk *)vchunk)->start != ptr);
}

t_dllist	*find_chunk(void *ptr)
{
	t_heap	*heap;

	heap = get_heap();
	return (ft_dllstfind(heap->meta, ptr, cmp_ptrs));
}

t_heap	*get_heap(void)
{
	static t_heap	heap = {0};

	if (!heap.meta)
	{
		heap.meta = ft_dllstnew(new_heap_chunk(
					heap.data,
					ALLOC_HEAP_CAPACITY,
					1));
	}
	return (&heap);
}

t_chunk	*new_heap_chunk(void *start, size_t size, int is_free)
{
	t_chunk	*out;

	out = malloc(sizeof(t_chunk));
	out->start = start;
	out->size = size;
	out->is_free = is_free;
	return (out);
}
