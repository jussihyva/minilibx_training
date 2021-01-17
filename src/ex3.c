/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:33:41 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 19:48:25 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int		render_next_frame(void *mlx_win)
{
	static int		cnt = 0;

	(void)mlx_win;
	cnt++;
	ft_printf("Frame rendering function call: %d!\n", cnt);
	return (0);
}

static void		initialize_win(t_mlx_win *mlx_win)
{
	mlx_win->win = mlx_new_window(mlx_win->mlx, 1920, 1080,
												"Minilibx training 3 (ex3)");
	mlx_hook(mlx_win->win, 2, 0x01, key_press, mlx_win);
	mlx_hook(mlx_win->win, 4, 0x04, key_press, mlx_win);
	mlx_hook(mlx_win->win, 6, 0x40, motion_notify, mlx_win);
	mlx_hook(mlx_win->win, 7, 0x10, enter_notify, mlx_win);
	mlx_hook(mlx_win->win, 8, 0x20, leave_notify, mlx_win);
	mlx_hook(mlx_win->win, 33, 0x00, close_win, mlx_win);
	return ;
}

int		main(void)
{
	t_mlx_win	*mlx_win;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->mlx = mlx_init();
	initialize_win(mlx_win);
	mlx_loop_hook(mlx_win->mlx, render_next_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}