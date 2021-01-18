/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elem_positions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 05:17:52 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 05:18:52 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		set_elem_position(t_position *elem_position, int x, int y,
																		int z)
{
	elem_position->x = x;
	elem_position->y = y;
	elem_position->z = z;
}

t_position		*set_elem_positions(t_elem_size *elem_size)
{
	t_position		*elem_positions;
	int				num_of_positions;

	num_of_positions = 8;
	elem_positions = (t_position *)ft_memalloc(sizeof(*elem_positions) *
															num_of_positions);
	set_elem_position(&elem_positions[0], 0, 0, 0);
	set_elem_position(&elem_positions[1], elem_size->x, 0, 0);
	set_elem_position(&elem_positions[2], 0, elem_size->y, 0);
	set_elem_position(&elem_positions[3], elem_size->x, elem_size->y, 0);
	set_elem_position(&elem_positions[4], 0, 0, elem_size->z);
	set_elem_position(&elem_positions[5], elem_size->x, 0, elem_size->z);
	set_elem_position(&elem_positions[6], 0, elem_size->y, elem_size->z);
	set_elem_position(&elem_positions[7], elem_size->x, elem_size->y,
																elem_size->z);
	return (elem_positions);
}
