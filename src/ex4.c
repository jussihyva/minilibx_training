/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:03:20 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 13:19:45 by jkauppi          ###   ########.fr       */
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
		x = start->x + i;
		y = start->y + (int)(i * y_len / x_len);
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
		y = start->y + i;
		x = start->x + (int)(i * x_len / y_len);
		mlx_image_pixel_put(element, x, y, color);
		i += step;
	}
	return ;
}

static void		draw_lines(t_element *element)
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

int				main(void)
{
	t_mlx_win	*mlx_win;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 4 (ex4)");
	mlx_win->element = create_element(mlx_win);
	draw_lines(mlx_win->element);
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
