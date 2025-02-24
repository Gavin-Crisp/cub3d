/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 09:17:08 by gcrisp            #+#    #+#             */
/*   Updated: 2024/01/09 12:14:36 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*ft_btreenew(size_t key, void *value)
{
	t_btree	*new;

	new = malloc(sizeof(t_btree));
	new->left = 0;
	new->right = 0;
	new->key = key;
	new->value = value;
	return (new);
}
