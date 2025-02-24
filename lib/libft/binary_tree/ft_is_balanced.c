/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_balanced.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:09:52 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:33 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_btreeis_balanced(t_btree *root)
{
	int	bal;

	if (!root)
		return (1);
	if (!ft_btreeis_balanced(root->left))
		return (0);
	if (!ft_btreeis_balanced(root->right))
		return (0);
	bal = ft_btreebalance_factor(root);
	return (-2 < bal && bal < 2);
}
