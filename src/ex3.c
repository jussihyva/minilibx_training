/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:33:41 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/22 12:23:39 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(void)
{
	t_mlx_win	*mlx_win;
	t_position	elem_start_position;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 3 (ex3)");
	set_position(&elem_start_position, 0, 0, 0);
	mlx_win->element1 = create_element(mlx_win, &elem_start_position);
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
