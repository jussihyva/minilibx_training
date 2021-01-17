/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex1.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:30:37 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 19:44:41 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	EVENT handling exercise
**	This exercise shows how to exit from window using ESC-key or
**	pressing red X on top right corner
**	Mouse location on the window or out of the window is recognized.
**	Mouse location (x and y values) are printed.
*/

#include "ex.h"

int			main(void)
{
	t_mlx_win		*mlx_win;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->mlx = mlx_init();
	mlx_win->win = mlx_new_window(mlx_win->mlx, 1920, 1080,
												"Minilibx training 1 (ex1)");
	mlx_hook(mlx_win->win, 2, 0x01, key_press, mlx_win);
	mlx_hook(mlx_win->win, 4, 0x04, key_press, mlx_win);
	mlx_hook(mlx_win->win, 6, 0x40, motion_notify, mlx_win);
	mlx_hook(mlx_win->win, 7, 0x10, enter_notify, mlx_win);
	mlx_hook(mlx_win->win, 8, 0x20, leave_notify, mlx_win);
	mlx_hook(mlx_win->win, 33, 0x00, close_win, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
