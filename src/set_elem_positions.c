/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:17:52 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/22 12:45:41 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void			set_position(t_position *position, int x, int y, int z)
{
	position->x = x;
	position->y = y;
	position->z = z;
}

t_position		*set_elem_positions(t_elem_size *elem_size,
													t_position *start_position)
{
	size_t			i;
	t_position		*elem_positions;

	elem_positions = (t_position *)ft_memalloc(sizeof(*elem_positions) *
														NUM_OF_ELEM_POSITIONS);
	set_position(&elem_positions[0], 0, 0, 0);
	set_position(&elem_positions[1], elem_size->x, 0, 0);
	set_position(&elem_positions[2], 0, elem_size->y, 0);
	set_position(&elem_positions[3], elem_size->x, elem_size->y, 0);
	set_position(&elem_positions[4], 0, 0, elem_size->z);
	set_position(&elem_positions[5], elem_size->x, 0, elem_size->z);
	set_position(&elem_positions[6], 0, elem_size->y, elem_size->z);
	set_position(&elem_positions[7], elem_size->x, elem_size->y, elem_size->z);
	i = -1;
	while (++i < NUM_OF_ELEM_POSITIONS)
	{
		elem_positions[i].x += start_position->x;
		elem_positions[i].y += start_position->y;
		elem_positions[i].z += start_position->z;
	}
	return (elem_positions);
}
