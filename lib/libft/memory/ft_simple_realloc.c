/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simple_realloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:30:50 by gcrisp            #+#    #+#             */
/*   Updated: 2025/03/13 13:56:35 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_simple_realloc(void *p, size_t old, size_t new)
{
	void	*out;

	out = malloc(new);
	if (p)
	{
		if (new < old)
			ft_memmove(out, p, new);
		else
			ft_memmove(out, p, old);
		free(p);
	}
	return (out);
}
