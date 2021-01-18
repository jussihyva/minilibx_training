/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:44:46 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 12:44:03 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static t_elem_size	*set_element_size(void)
{
	t_elem_size		*elem_size;

	elem_size = (t_elem_size *)ft_memalloc(sizeof(*elem_size));
	elem_size->x = 150;
	elem_size->y = 150;
	elem_size->z = 150;
	return (elem_size);
}

static void			set_elem_line(t_elem_line *elem_line, t_position *start,
																t_position *end)
{
	elem_line->start = start;
	elem_line->end = end;
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

t_element			*create_element(t_mlx_win *mlx_win)
{
	t_element	*element;
	int			i;
	int			x_len;
	int			y_len;

	x_len = 200;
	y_len = 200;
	element = (t_element *)ft_memalloc(sizeof(*element));
	element->elem_size = set_element_size();
	element->elem_positions = set_elem_positions(element->elem_size);
	element->elem_lines = set_elem_lines(element->elem_positions);
	element->next_position.x = 20;
	element->next_position.y = 20;
	element->current_position.x = -1;
	element->current_position.y = -1;
	element->empty_img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	element->img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	element->addr = mlx_get_data_addr(element->img, &(element->bits_per_pixel),
								&(element->line_length), &(element->endian));
	i = -1;
	while (++i < 10)
		mlx_image_pixel_put(element, i, i, 0x00FF0000);
	mlx_win->render_action = e_put_image_to_window;
	return (element);
}
