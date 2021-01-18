/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:03:20 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 04:03:37 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int				main(void)
{
	t_mlx_win	*mlx_win;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 4 (ex4)");
	mlx_win->element = create_element(mlx_win);
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
