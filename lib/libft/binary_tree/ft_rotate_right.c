/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 10:27:42 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:42 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreerotate_right(t_btree **rootptr)
{
	t_btree	*pivot;

	if (!*rootptr)
		return ;
	if (!(*rootptr)->left)
		return ;
	pivot = (*rootptr)->left;
	(*rootptr)->left = pivot->right;
	pivot->right = *rootptr;
	*rootptr = pivot;
}
