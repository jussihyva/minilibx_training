/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/07 00:16:44 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		change_angle(int keycode, t_position *angle, int angle_step)
{
	if (keycode == 'a')
		angle->x = (angle->x + angle_step) % 360;
	else if (keycode == 'z')
		angle->x = (angle->x >= angle_step) ? (angle->x - angle_step) % 360 :
												(angle->x + 360 - angle_step);
	else if (keycode == 's')
		angle->y = (angle->y + angle_step) % 360;
	else if (keycode == 'x')
		angle->y = (angle->y >= angle_step) ? (angle->y - angle_step) % 360 :
												(angle->y + 360 - angle_step);
	else if (keycode == 'd')
		angle->z = (angle->z + angle_step) % 360;
	else if (keycode == 'c')
		angle->z = (angle->z >= angle_step) ? (angle->z - angle_step) % 360 :
												(angle->z + 360 - angle_step);
	return ;
}

int				button_press(int keycode, int x, int y, t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("Key: %d, Mouse location: x:%d, y:%d\n", keycode, x, y);
	return (0);
}

int				key_press(int keycode, t_mlx_win *mlx_win)
{
	t_position		*position_offset;
	size_t			i;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	if (keycode == 65307)
		close_win(mlx_win);
	else if (mlx_win->render_action != e_no_action)
		;
	else if (ft_strchr("asdzxc", keycode))
	{
		change_angle(keycode, mlx_win->angle, mlx_win->angle_step);
		ft_bzero(mlx_win->img->data, 600 * mlx_win->img->size_line / 4 +
										600 * (mlx_win->img->bpp / 8));
		i = -1;
		while (++i < mlx_win->num_of_elements)
		{
			if (i)
				ft_memcpy(mlx_win->elem_array[i]->start_position,
					&mlx_win->elem_array[i - 1]->elem_positions[1],
					sizeof(*mlx_win->elem_array[i]->start_position));
			elemental_rotation(mlx_win->elem_array[i], mlx_win->angle,
							position_offset, mlx_win->elem_array[i]->start_position);
		}
		i = -1;
		while (++i < mlx_win->num_of_elements)
		{
			mlx_win->elem_array[i]->elem_position_offset.x = position_offset->x;
			mlx_win->elem_array[i]->elem_position_offset.y = position_offset->y;
			if (i)
			{
				mlx_win->elem_array[i]->elem_position_offset.x += mlx_win->elem_array[i - 1]->elem_positions[1].x;
				mlx_win->elem_array[i]->elem_position_offset.y += mlx_win->elem_array[i - 1]->elem_positions[1].y;
			}
			draw_lines(mlx_win->img, mlx_win->elem_array[i]);
		}
		mlx_win->render_action = e_put_image_to_window;
	}
	else
		ft_printf("keycode: %#x\n", keycode);
	ft_memdel((void **)&position_offset);
	return (0);
}
