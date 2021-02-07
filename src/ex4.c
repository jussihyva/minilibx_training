/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:03:20 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 19:07:41 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(int argc, char **argv)
{
	t_mlx_win	*mlx_win;
	t_position	elem_start_position;
	t_position	*position_offset;
	int			x_len;
	int			y_len;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	x_len = 600;
	y_len = 600;
	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->img_next_position =
				(t_position *)ft_memalloc(sizeof(*mlx_win->img_next_position));
	mlx_win->render_action = e_no_action;
	mlx_win->angle = read_cmd_arguments(argc, argv);
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 4 (ex4)");
	mlx_win->empty_img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	mlx_win->img = mlx_new_image(mlx_win->mlx, x_len, y_len);
	set_position(&elem_start_position, 0, 0, 0);
	mlx_win->element1 = create_element(mlx_win, &elem_start_position,
															position_offset);
	ft_memcpy(&mlx_win->img_start_position, &elem_start_position,
										sizeof(mlx_win->img_start_position));
	ft_memcpy(mlx_win->img_next_position, &elem_start_position,
										sizeof(*mlx_win->img_next_position));
	mlx_win->img_current_position.x = -1;
	mlx_win->img_current_position.y = -1;
	ft_printf("Start X: %d\n", mlx_win->element1->elem_positions[1].x);
	ft_printf("Start Y: %d\n", mlx_win->element1->elem_positions[1].y);
	ft_printf("Start Z: %d\n", mlx_win->element1->elem_positions[1].z);
	elem_start_position = mlx_win->element1->elem_positions[1];
	mlx_win->element2 = create_element(mlx_win, &elem_start_position,
															position_offset);
	mlx_win->element1->elem_position_offset.x = position_offset->x;
	mlx_win->element1->elem_position_offset.y = position_offset->y;
	mlx_win->element2->elem_position_offset.x = position_offset->x +
										mlx_win->element1->elem_positions[1].x;
	mlx_win->element2->elem_position_offset.y = position_offset->y +
										mlx_win->element1->elem_positions[1].y;
	draw_lines(mlx_win->img, mlx_win->element1);
	draw_lines(mlx_win->img, mlx_win->element2);
	mlx_win->render_action = e_put_image_to_window;
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	ft_memdel((void **)position_offset);
	return (0);
}
