/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frame.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:31:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 20:25:39 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		render_frame(t_mlx_win *mlx_win)
{
	if (mlx_win->render_action == e_put_image_to_window)
	{
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win,
							mlx_win->empty_img, mlx_win->img_start_position->x,
											mlx_win->img_start_position->y);
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win, mlx_win->img,
				mlx_win->img_start_position->x, mlx_win->img_start_position->y);
		mlx_win->render_action = e_no_action;
	}
	return (0);
}
