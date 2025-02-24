/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:32:41 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:21 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeclear(t_btree **rootptr, void (*fr)(void *))
{
	if (*rootptr)
	{
		ft_btreeclear(&(*rootptr)->left, fr);
		ft_btreeclear(&(*rootptr)->right, fr);
		fr((*rootptr)->value);
		free(*rootptr);
		*rootptr = 0;
	}
}
