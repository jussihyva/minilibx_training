/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/08 12:05:50 by jkauppi          ###   ########.fr       */
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
	int				i;
	int				j;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	if (keycode == 65307)
		close_win(mlx_win);
	else if (mlx_win->render_action != e_no_action)
		;
	else if (ft_strchr("asdzxc", keycode))
	{
		change_angle(keycode, mlx_win->angle, mlx_win->angle_step);
		ft_bzero(mlx_win->img->data, 2000 * mlx_win->img->size_line / 4 +
										2000 * (mlx_win->img->bpp / 8));
		i = -1;
		while (++i < 1)
		{
			j = -1;
			while (++j < mlx_win->element_map_size->x)
			{
				if (j)
				{
					ft_memcpy(mlx_win->elem_array[j]->start_position,
						&mlx_win->elem_array[j - 1]->current_positions[1],
						sizeof(*mlx_win->elem_array[j]->start_position));
					mlx_win->elem_array[j]->start_position->x *= j;
					mlx_win->elem_array[j]->start_position->y *= j;
					mlx_win->elem_array[j]->start_position->z *= j;
				}
				elemental_rotation(mlx_win->elem_array[j], mlx_win->angle,
								position_offset, mlx_win->elem_array[j]->start_position);
			}
		}
		i = -1;
		while (++i < (int)mlx_win->num_of_elements)
		{
			mlx_win->elem_array[i]->elem_position_offset.x = position_offset->x + mlx_win->elem_array[i]->start_position->x;
			mlx_win->elem_array[i]->elem_position_offset.y = position_offset->y + mlx_win->elem_array[i]->start_position->y;
			draw_lines(mlx_win->img, mlx_win->elem_array[i]);
		}
		mlx_win->render_action = e_put_image_to_window;
	}
	else
		ft_printf("keycode: %#x\n", keycode);
	ft_memdel((void **)&position_offset);
	return (0);
}
