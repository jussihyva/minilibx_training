/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/22 12:43:46 by juhani           ###   ########.fr       */
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
	t_element		*element1;
	t_element		*element2;

	element1 = mlx_win->element1;
	element2 = mlx_win->element2;
	if (keycode == 65307)
		close_win(mlx_win);
	else if (keycode == 0x31)
	{
		element1->next_position.x = element1->current_position.x + 20;
		element1->next_position.y = element1->current_position.y + 20;
		mlx_win->render_action = e_put_image_to_window;
	}
	else if (keycode == 0x32)
	{
		if (mlx_win->render_action == e_no_action)
		{
			z_elemental_rotation(element1);
			z_elemental_rotation(element2);
			ft_printf("Offset: %0.2f %0.2f %0.2f\n",
											element1->elem_position_offset.x,
											element1->elem_position_offset.y,
											element1->elem_position_offset.z);
			ft_bzero(element1->addr, 600 * element1->line_length +
										600 * (element1->bits_per_pixel / 8));
			ft_bzero(element2->addr, 600 * element2->line_length +
										600 * (element2->bits_per_pixel / 8));
			draw_lines(element1);
			draw_lines(element2);
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
