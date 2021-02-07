/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:31:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 16:47:22 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		render_frame(t_mlx_win *mlx_win)
{
	t_element		*element;
	t_element		*element_arrray[2];
	size_t			i;

	if (mlx_win->render_action == e_put_image_to_window)
	{
		element_arrray[0] = mlx_win->element1;
		element_arrray[1] = mlx_win->element2;
		i = -1;
		while (++i < 2)
		{
			element = element_arrray[i];
			element->current_position = *element->next_position;
		}
		if (mlx_win->img_current_position.x != -1 &&
										mlx_win->img_current_position.y != -1)
			mlx_put_image_to_window(mlx_win->mlx, mlx_win->win,
							mlx_win->empty_img, mlx_win->img_current_position.x,
											mlx_win->img_current_position.y);
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win, mlx_win->img,
				mlx_win->img_next_position->x, mlx_win->img_next_position->y);
		mlx_win->render_action = e_no_action;
	}
	return (0);
}
