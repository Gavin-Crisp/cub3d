/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:25:54 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 12:25:55 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_H
# define ALLOCATOR_H
# include "libft.h"

typedef struct s_heap
{
	t_dllist		*meta;
	unsigned char	data[ALLOC_HEAP_CAPACITY];
}	t_heap;

typedef struct s_chunk
{
	void	*start;
	size_t	size;
	int		is_free;
}	t_chunk;

void		free_chunk(t_dllist **pchunks);

t_heap		*get_heap(void);
t_chunk		*new_heap_chunk(void *start, size_t size, int is_free);
t_dllist	*find_chunk(void *ptr);

#endif
