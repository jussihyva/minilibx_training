/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 13:30:50 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		key_press(int keycode, t_mlx_win *mlx_win)
{
	if (keycode == 65307)
		close_win(mlx_win);
	else
		ft_printf("keycode: %d\n", keycode);
	return (0);
}

int		motion_notify(int x, int y, t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("Mouse location: x:%d, y:%d\n", x, y);
	return (0);
}

int		enter_notify(t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("On the window\n");
	return (0);
}

int		leave_notify(t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("Out of the window\n");
	return (0);
}
