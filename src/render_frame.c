/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:31:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 03:53:14 by jkauppi          ###   ########.fr       */
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
		ft_printf("Frame rendering function call: %d!\n", cnt);
		element = mlx_win->element;
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
