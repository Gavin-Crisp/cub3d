/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 13:39:47 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:45 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreesearch(t_btree *root, size_t key)
{
	if (!root)
		return (0);
	if (key == root->key)
		return (root);
	if (key < root->key)
		return (ft_btreesearch(root->left, key));
	return (ft_btreesearch(root->right, key));
}
