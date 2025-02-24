/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:48:13 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/24 16:50:40 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t n)
{
	void	*tmp;

	tmp = malloc(n);
	ft_memcpy(tmp, a, n);
	ft_memmove(a, b, n);
	ft_memcpy(b, tmp, n);
	free(tmp);
}
