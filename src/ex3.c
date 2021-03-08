/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:33:41 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/08 15:55:05 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(int argc, char **argv)
{
	t_mlx_win			*mlx_win;
	t_position			elem_start_position;
	t_position			*position_offset;
	t_position			elem_size;
	t_input				*input;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	input = read_cmd_arguments(argc, argv);
	mlx_win->angle = input->angle;
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 3 (ex3)");
	set_position(&elem_start_position, 0, 0, 0);
	set_position(&elem_size, 50, 50, 50);
	mlx_win->elem_table[0][0] = create_element(mlx_win, &elem_start_position,
												position_offset, &elem_size);
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	release_input_data(&input);
	ft_memdel((void **)position_offset);
	return (0);
}
