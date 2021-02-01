/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_element_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 23:12:39 by juhani            #+#    #+#             */
/*   Updated: 2021/02/01 01:54:35 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void			draw_lines(t_element *element)
{
	t_elem_line *elem_lines;
	int			i;

	elem_lines = element->elem_lines;
	i = -1;
	while (++i < 12)
	{
		if (i == 1 || i == 5 || i == 6)
			elem_lines[i].line_type = 1;
		elem_lines[i].color = 0x00FF0000;
		bresenham_draw_line(element->img, &elem_lines[i],
												&element->elem_position_offset);
	}
	return ;
}
