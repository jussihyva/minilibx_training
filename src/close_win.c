/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 12:49:57 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 19:22:00 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

int		close_win(t_mlx_win *mlx_win)
{
	mlx_loop_end(mlx_win->mlx);
	mlx_destroy_window(mlx_win->mlx, mlx_win->win);
	return (0);
}
