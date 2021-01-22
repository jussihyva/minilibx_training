/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:57:26 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/22 11:44:03 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void		initialize_window(t_mlx_win *mlx_win, char *window_name)
{
	mlx_win->win = mlx_new_window(mlx_win->mlx, 700, 1080, window_name);
	mlx_hook(mlx_win->win, 2, 0x01, key_press, mlx_win);
	mlx_hook(mlx_win->win, 4, 0x04, button_press, mlx_win);
	mlx_hook(mlx_win->win, 6, 0x40, motion_notify, mlx_win);
	mlx_hook(mlx_win->win, 7, 0x10, enter_notify, mlx_win);
	mlx_hook(mlx_win->win, 8, 0x20, leave_notify, mlx_win);
	mlx_hook(mlx_win->win, 33, 0x00, close_win, mlx_win);
	return ;
}
