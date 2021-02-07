/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_functions1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:47:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 19:55:46 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		change_angle(int keycode, t_position *angle)
{
	if (keycode == 'a')
		angle->x = (angle->x + 1) % 360;
	else if (keycode == 'z')
		angle->x = (angle->x) ? (angle->x - 1) % 360 : 359;
	else if (keycode == 's')
		angle->y = (angle->y + 1) % 360;
	else if (keycode == 'x')
		angle->y = (angle->y) ? (angle->y - 1) % 360 : 359;
	else if (keycode == 'd')
		angle->z = (angle->z + 1) % 360;
	else if (keycode == 'c')
		angle->z = (angle->z) ? (angle->z - 1) % 360 : 359;
	return ;
}

int				button_press(int keycode, int x, int y, t_mlx_win *mlx_win)
{
	(void)mlx_win;
	ft_printf("Key: %d, Mouse location: x:%d, y:%d\n", keycode, x, y);
	return (0);
}

void			change_element_position(t_img *img, t_element *element,
								t_position *angle, t_position *position_offset)
{
	elemental_rotation(element, angle, position_offset, element->next_position);
	draw_lines(img, element);
	return ;
}

int				key_press(int keycode, t_mlx_win *mlx_win)
{
	t_element		*element_arrray[2];
	t_position		*position_offset;
	size_t			i;

	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	if (keycode == 65307)
		close_win(mlx_win);
	else if (mlx_win->render_action != e_no_action)
		;
	else if (ft_strchr("asdzxc", keycode))
	{
		change_angle(keycode, mlx_win->angle);
		element_arrray[0] = mlx_win->element1;
		element_arrray[1] = mlx_win->element2;
		ft_bzero(mlx_win->img->data, 600 * mlx_win->img->size_line / 4 +
										600 * (mlx_win->img->bpp / 8));
		i = -1;
		while (++i < 2)
		{
			if (i)
				ft_memcpy(mlx_win->element2->next_position,
					&mlx_win->element1->elem_positions[1],
					sizeof(*mlx_win->element2->next_position));
			change_element_position(mlx_win->img, element_arrray[i],
											mlx_win->angle, position_offset);
		}
		mlx_win->element1->elem_position_offset.x = position_offset->x;
		mlx_win->element1->elem_position_offset.y = position_offset->y;
		mlx_win->element2->elem_position_offset.x = position_offset->x +
										mlx_win->element1->elem_positions[1].x;
		mlx_win->element2->elem_position_offset.y = position_offset->y +
										mlx_win->element1->elem_positions[1].y;
		mlx_win->render_action = e_put_image_to_window;
	}
	else
		ft_printf("keycode: %#x\n", keycode);
	ft_memdel((void **)position_offset);
	return (0);
}
