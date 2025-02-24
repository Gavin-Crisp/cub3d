/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:59:25 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:24 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_btreeheight(t_btree *root)
{
	size_t	left;
	size_t	right;

	if (!root)
		return (0);
	left = ft_btreeheight(root->left);
	right = ft_btreeheight(root->right);
	if (left > right)
		return (left + 1);
	return (right + 1);
}
