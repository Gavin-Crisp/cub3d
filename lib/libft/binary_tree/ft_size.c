/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:22:31 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:49 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_btreesize(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_btreesize(root->left)
		+ ft_btreesize(root->right) + 1);
}
