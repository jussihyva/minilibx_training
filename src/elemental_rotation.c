/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemental_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:46:08 by juhani            #+#    #+#             */
/*   Updated: 2021/01/22 12:41:21 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static double	d_one(double nbr)
{
	(void)nbr;
	return ((double)1);
}

static double	d_zero(double nbr)
{
	(void)nbr;
	return ((double)0);
}

static double	neg_sin(double nbr)
{
	return (-sin(nbr));
}

static void		z_rotation(t_position *elem_position)
{
	double			degree;
	t_position		new_elem_position;
	double			new_value;
	static double	(*function[3][3])(double) = {{cos, neg_sin, d_zero},
												{sin, cos, d_zero},
												{d_zero, d_zero, d_one}};

	ft_printf("Old values: %0.2f %0.2f %0.2f\n", elem_position->x,
											elem_position->y, elem_position->z);
	degree = RADIAN(5);
	new_value = (*function[0][0])(degree) * elem_position->x;
	new_value += (*function[0][1])(degree) * elem_position->y;
	new_value += (*function[0][2])(degree) * elem_position->z;
	new_elem_position.x = new_value;
	new_value = (*function[1][0])(degree) * elem_position->x;
	new_value += (*function[1][1])(degree) * elem_position->y;
	new_value += (*function[1][2])(degree) * elem_position->z;
	new_elem_position.y = new_value;
	new_value = (*function[2][0])(degree) * elem_position->x;
	new_value += (*function[2][1])(degree) * elem_position->y;
	new_value += (*function[2][2])(degree) * elem_position->z;
	new_elem_position.z = new_value;
	ft_memcpy(elem_position, &new_elem_position, sizeof(new_elem_position));
	return ;
}

void			z_elemental_rotation(t_element *element)
{
	size_t		i;
	t_position	*position_offset;
	t_position	*elem_positions;

	elem_positions = element->elem_positions;
	position_offset = &element->elem_position_offset;
	ft_bzero(position_offset, sizeof(*position_offset));
	i = -1;
	while (++i < NUM_OF_ELEM_POSITIONS)
	{
		z_rotation(&(elem_positions[i]));
		ft_printf("New values: %0.2f %0.2f %0.2f\n", elem_positions[i].x,
									elem_positions[i].y, elem_positions[i].z);
		position_offset->x = MAX(position_offset->x, -elem_positions[i].x);
		position_offset->y = MAX(position_offset->y, -elem_positions[i].y);
		position_offset->z = MAX(position_offset->z, -elem_positions[i].z);
	}
	return ;
}
