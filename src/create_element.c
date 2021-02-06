/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:44:46 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/06 16:50:19 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static t_elem_size	*set_element_size(void)
{
	t_elem_size		*elem_size;

	elem_size = (t_elem_size *)ft_memalloc(sizeof(*elem_size));
	elem_size->x = 50;
	elem_size->y = 50;
	elem_size->z = 50;
	return (elem_size);
}

static void			set_elem_line(t_elem_line *elem_line, t_position *start,
																t_position *end)
{
	elem_line->start = start;
	elem_line->end = end;
	// elem_line->color = 
	elem_line->line_type = 0;
	return ;
}

static t_elem_line	*set_elem_lines(t_position *elem_positions)
{
	t_elem_line		*elem_lines;
	int				num_of_lines;

	num_of_lines = 12;
	elem_lines = (t_elem_line *)ft_memalloc(sizeof(*elem_lines) *
																num_of_lines);
	set_elem_line(&elem_lines[0], &elem_positions[0], &elem_positions[1]);
	set_elem_line(&elem_lines[1], &elem_positions[0], &elem_positions[2]);
	set_elem_line(&elem_lines[2], &elem_positions[0], &elem_positions[4]);
	set_elem_line(&elem_lines[3], &elem_positions[1], &elem_positions[3]);
	set_elem_line(&elem_lines[4], &elem_positions[1], &elem_positions[5]);
	set_elem_line(&elem_lines[5], &elem_positions[2], &elem_positions[3]);
	set_elem_line(&elem_lines[6], &elem_positions[2], &elem_positions[6]);
	set_elem_line(&elem_lines[7], &elem_positions[3], &elem_positions[7]);
	set_elem_line(&elem_lines[8], &elem_positions[4], &elem_positions[5]);
	set_elem_line(&elem_lines[9], &elem_positions[4], &elem_positions[6]);
	set_elem_line(&elem_lines[10], &elem_positions[5], &elem_positions[7]);
	set_elem_line(&elem_lines[11], &elem_positions[6], &elem_positions[7]);
	return (elem_lines);
}

t_element			*create_element(t_mlx_win *mlx_win,
													t_position *start_position)
{
	t_element	*element;
	int			x_len;
	int			y_len;

	x_len = 600;
	y_len = 600;
	element = (t_element *)ft_memalloc(sizeof(*element));
	element->angle = (t_position *)ft_memalloc(sizeof(*mlx_win->angle));
	element->elem_size = set_element_size();
	ft_memcpy(element->angle, mlx_win->angle, sizeof(*mlx_win->angle));
	element->elem_positions = set_elem_positions(element->elem_size);
	element->elem_start_positions = 
			(t_position *)ft_memalloc(sizeof(*element->elem_start_positions) *
														NUM_OF_ELEM_POSITIONS);
	ft_memcpy(element->elem_start_positions, element->elem_positions,
					sizeof(*element->elem_positions) * NUM_OF_ELEM_POSITIONS);
	elemental_rotation(element, element->angle);
	element->elem_lines = set_elem_lines(element->elem_positions);
	ft_memcpy(&element->start_position, start_position, sizeof(*start_position));
	element->next_position.x = start_position->x;
	element->next_position.y = start_position->y;
	element->current_position.x = -1;
	element->current_position.y = -1;
	element->empty_img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	element->img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	element->addr = mlx_get_data_addr(element->img, &(element->bits_per_pixel),
								&(element->line_length), &(element->endian));
	return (element);
}
