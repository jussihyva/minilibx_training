/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:03:20 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/29 23:09:31 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(int argc, char **argv)
{
	t_mlx_win	*mlx_win;
	t_position	elem1_start_position;
	t_position	elem2_start_position;
	t_position	*angle;

	angle = read_cmd_arguments(argc, argv);
	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 4 (ex4)");
	set_position(&elem1_start_position, 0, 0, 0);
	set_position(&elem2_start_position, 200, 200, 200);
	mlx_win->element1 = create_element(mlx_win, &elem1_start_position, angle);
	mlx_win->element2 = create_element(mlx_win, &elem2_start_position, angle);
	ft_memdel((void **)&angle);
	draw_lines(mlx_win->element1);
	draw_lines(mlx_win->element2);
	mlx_win->render_action = e_put_image_to_window;
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
