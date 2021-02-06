/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/06 16:49:30 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		button_press(int keycode, int x, int y, t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("Key: %d, Mouse location: x:%d, y:%d\n", keycode, x, y);
	return (0);
}

int		key_press(int keycode, t_mlx_win *mlx_win)
{
	t_element		*element;
	// t_element		*element2;

	element = mlx_win->element1;
	// element2 = mlx_win->element2;
	if (keycode == 65307)
		close_win(mlx_win);
	else if (keycode == 0x31)
	{
		// element1->next_position.x = element1->current_position.x + 20;
		// element1->next_position.y = element1->current_position.y + 20;
		mlx_win->render_action = e_put_image_to_window;
	}
	else if (ft_strchr("asdzxc", keycode))
	{
		if (mlx_win->render_action == e_no_action)
		{
			if (keycode == 'a')
				mlx_win->angle->x = (mlx_win->angle->x + 1) % 360;
			if (keycode == 'z')
			{
				if (mlx_win->angle->x)
					mlx_win->angle->x = (mlx_win->angle->x - 1) % 360;
				else
					mlx_win->angle->x = 359;
			}
			if (keycode == 's')
				mlx_win->angle->y = (mlx_win->angle->y + 1) % 360;
			if (keycode == 'x')
			{
				if (mlx_win->angle->y)
					mlx_win->angle->y = (mlx_win->angle->y - 1) % 360;
				else
					mlx_win->angle->y = 359;
			}
			if (keycode == 'd')
				mlx_win->angle->z = (mlx_win->angle->z + 1) % 360;
			if (keycode == 'c')
			{
				if (mlx_win->angle->z)
					mlx_win->angle->z = (mlx_win->angle->z - 1) % 360;
				else
					mlx_win->angle->z = 359;
			}
			elemental_rotation(mlx_win->element1, mlx_win->angle);
			ft_bzero(mlx_win->element1->addr, 600 * mlx_win->element1->line_length +
										600 * (mlx_win->element1->bits_per_pixel / 8));
			draw_lines(mlx_win->element1);
			ft_memcpy(&mlx_win->element2->next_position,
						&mlx_win->element1->elem_positions[1],
						sizeof(mlx_win->element2->next_position));
			elemental_rotation(mlx_win->element2, mlx_win->angle);
			ft_bzero(mlx_win->element2->addr, 600 * mlx_win->element2->line_length +
										600 * (mlx_win->element2->bits_per_pixel / 8));
			draw_lines(mlx_win->element2);
			mlx_win->render_action = e_put_image_to_window;
		}
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
