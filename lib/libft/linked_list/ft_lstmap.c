/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:40:43 by gcrisp            #+#    #+#             */
/*   Updated: 2023/05/09 11:30:20 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*out;

	out = 0;
	while (lst)
	{
		ft_lstadd_back(&out, ft_lstnew(f(lst->data)));
		lst = lst->next;
	}
	return (out);
}
