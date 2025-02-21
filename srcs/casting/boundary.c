/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boundary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrisp <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:25:29 by gcrisp            #+#    #+#             */
/*   Updated: 2025/02/21 13:25:30 by gcrisp           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <casting.h>

t_boundary	*new_boundary(double x1, double y1, double x2, double y2)
{
	t_boundary	*out;

	out = malloc(sizeof(t_boundary));
	out->end1 = new_point(x1, y1);
	out->end2 = new_point(x2, y2);
	return (out);
}

void	free_boundary(t_boundary *bound)
{
	if (!bound)
		return ;
	free(bound->end1);
	free(bound->end2);
	free(bound);
}

void	free_boundary_array(t_boundary *bounds, size_t num_bounds)
{
	if (!bounds)
		return ;
	while (num_bounds--)
	{
		free(bounds[num_bounds].end1);
		free(bounds[num_bounds].end2);
	}
	free(bounds);
}
