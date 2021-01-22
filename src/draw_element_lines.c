/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:12:39 by juhani            #+#    #+#             */
/*   Updated: 2021/01/22 08:18:41 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		draw_line_x(t_element *element, t_position *start, int x_len,
																	int y_len)
{
	int			i;
	int			x;
	int			y;
	int			step;
	int			color;

	color = 0x00FF0000;
	step = (x_len < 0) ? -1 : 1;
	i = 0;
	while (i != x_len)
	{
		x = start->x + element->elem_position_offset.x + i;
		y = start->y + element->elem_position_offset.y +
													(int)(i * y_len / x_len);
		mlx_image_pixel_put(element, x, y, color);
		i += step;
	}
	return ;
}

static void		draw_line_y(t_element *element, t_position *start, int x_len,
																	int y_len)
{
	int			i;
	int			x;
	int			y;
	int			step;
	int			color;

	color = 0x00FF0000;
	step = (y_len < 0) ? -1 : 1;
	i = 0;
	while (i != y_len)
	{
		y = start->y + element->elem_position_offset.y + i;
		x = start->x + element->elem_position_offset.x +
													(int)(i * x_len / y_len);
		mlx_image_pixel_put(element, x, y, color);
		i += step;
	}
	return ;
}

void			draw_lines(t_element *element)
{
	t_elem_line *elem_lines;
	int			x_len;
	int			y_len;
	int			i;

	elem_lines = element->elem_lines;
	i = -1;
	while (++i < 12)
	{
		x_len = elem_lines[i].end->x - elem_lines[i].start->x;
		y_len = elem_lines[i].end->y - elem_lines[i].start->y;
		if (x_len > y_len)
			draw_line_x(element, elem_lines[i].start, x_len, y_len);
		else
			draw_line_y(element, elem_lines[i].start, x_len, y_len);
	}
	return ;
}
