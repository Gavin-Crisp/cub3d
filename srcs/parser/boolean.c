/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boolean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:09:34 by gcrisp            #+#    #+#             */
/*   Updated: 2025/04/03 15:31:41 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_inside(char c)
{
	return (c == '0' || c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

int	is_outside(char c)
{
	return (c == ' ');
}

int	is_player(char c)
{
	return (c == 'N' || c == 'E' || c == 'S' || c == 'W');
}

int	is_empty(char c)
{
	return (c == '0');
}
