/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:38:45 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:39 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreerotate_left(t_btree **rootptr)
{
	t_btree	*pivot;

	if (!*rootptr)
		return ;
	if (!(*rootptr)->right)
		return ;
	pivot = (*rootptr)->right;
	(*rootptr)->right = pivot->left;
	pivot->left = *rootptr;
	*rootptr = pivot;
}
