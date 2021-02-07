/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:33:41 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 18:41:12 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(int argc, char **argv)
{
	t_mlx_win	*mlx_win;
	t_position	elem_start_position;
	t_position	*position_offset;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->angle = read_cmd_arguments(argc, argv);
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 3 (ex3)");
	set_position(&elem_start_position, 0, 0, 0);
	mlx_win->element1 = create_element(mlx_win, &elem_start_position,
															position_offset);
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	ft_memdel((void **)position_offset);
	return (0);
}
