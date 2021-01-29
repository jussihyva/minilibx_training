/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:31:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/30 00:05:01 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		render_frame(t_mlx_win *mlx_win)
{
	static int		cnt = 0;
	t_element		*element;

	cnt++;
	if (mlx_win->render_action == e_put_image_to_window)
	{
		// ft_printf("Frame rendering function call: %d!\n", cnt);
		element = mlx_win->element1;
		if (element->current_position.x != -1 &&
											element->current_position.y != -1)
			mlx_put_image_to_window(mlx_win->mlx, mlx_win->win,
								element->empty_img, element->current_position.x,
												element->current_position.y);
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win, element->img,
							element->next_position.x, element->next_position.y);
		element->current_position = element->next_position;
		element = mlx_win->element2;
		if (element->current_position.x != -1 &&
											element->current_position.y != -1)
			mlx_put_image_to_window(mlx_win->mlx, mlx_win->win,
								element->empty_img, element->current_position.x,
												element->current_position.y);
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win, element->img,
							element->next_position.x, element->next_position.y);
		element->current_position = element->next_position;
		mlx_win->render_action = e_no_action;
	}
	return (0);
}
