/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:20:47 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:27 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_btreeinsert(t_btree **rootptr, t_btree *new)
{
	if (!*rootptr)
		*rootptr = new;
	else
	{
		if (new->key < (*rootptr)->key)
			ft_btreeinsert(&(*rootptr)->left, new);
		else
			ft_btreeinsert(&(*rootptr)->right, new);
	}
}
