/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_balanced.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:33:57 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	balance(t_btree **rootptr, int right_heavy)
{
	if (right_heavy)
	{
		if (ft_btreebalance_factor((*rootptr)->right) >= 0)
			ft_btreerotate_left(rootptr);
		else
		{
			ft_btreerotate_right(&(*rootptr)->right);
			ft_btreerotate_left(rootptr);
		}
	}
	else
	{
		if (ft_btreebalance_factor((*rootptr)->left) <= 0)
			ft_btreerotate_right(rootptr);
		else
		{
			ft_btreerotate_left(&(*rootptr)->left);
			ft_btreerotate_right(rootptr);
		}
	}
}

void	ft_btreeinsert_balanced(t_btree **rootptr, t_btree *new)
{
	int	bal;

	if (!*rootptr)
	{
		*rootptr = new;
		return ;
	}
	if (new->key < (*rootptr)->key)
		ft_btreeinsert_balanced(&(*rootptr)->left, new);
	else
		ft_btreeinsert_balanced(&(*rootptr)->right, new);
	bal = ft_btreebalance_factor(*rootptr);
	if (bal <= -2 || 2 <= bal)
		balance(rootptr, bal > 0);
}
