/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 21:49:14 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		key_press(int keycode, t_mlx_win *mlx_win)
{
	if (keycode == 65307)
		close_win(mlx_win);
	else if (keycode == 0x31)
	{
		mlx_win->image->next_position.x =
										mlx_win->image->current_position.x + 20;
		mlx_win->image->next_position.y =
										mlx_win->image->current_position.y + 20;
		mlx_win->render_action = e_put_image_to_window;
	}
	else
		ft_printf("keycode: %#x\n", keycode);
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
