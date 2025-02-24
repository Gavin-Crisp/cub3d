/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   balance.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 13:55:35 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:15 by gcrisp           ###   ########.fr       */
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

void	ft_btreebalance(t_btree **rootptr)
{
	int	bal;

	if (!*rootptr)
		return ;
	ft_btreebalance(&(*rootptr)->left);
	ft_btreebalance(&(*rootptr)->right);
	bal = ft_btreebalance_factor(*rootptr);
	while (bal < -1 || 1 > bal)
	{
		balance(rootptr, bal > 0);
		bal = ft_btreebalance_factor(*rootptr);
	}
}
