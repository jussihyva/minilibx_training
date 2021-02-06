/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:41:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/06 16:36:37 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		release_rotation_matrix(double ***rotation_matrix,
														int *is_rotation_matrix)
{
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < 360)
	{
		if (is_rotation_matrix[i])
		{
			j = -1;
			while (++j < 3)
				ft_memdel((void **)&rotation_matrix[i][j]);
			ft_memdel((void **)&rotation_matrix[i]);
		}
	}
	return ;
}

void			release_mlx_win(t_mlx_win **mlx_win)
{
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element1->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element1->img);
	ft_memdel((void **)&(*mlx_win)->element1->elem_size);
	ft_memdel((void **)&(*mlx_win)->element1->elem_positions);
	ft_memdel((void **)&(*mlx_win)->element1->elem_start_positions);
	ft_memdel((void **)&(*mlx_win)->element1->elem_lines);
	ft_memdel((void **)&(*mlx_win)->element1->angle);
	ft_memdel((void **)&(*mlx_win)->element1);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element2->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element2->img);
	ft_memdel((void **)&(*mlx_win)->element2->elem_size);
	ft_memdel((void **)&(*mlx_win)->element2->elem_positions);
	ft_memdel((void **)&(*mlx_win)->element2->elem_start_positions);
	ft_memdel((void **)&(*mlx_win)->element2->elem_lines);
	ft_memdel((void **)&(*mlx_win)->element2->angle);
	ft_memdel((void **)&(*mlx_win)->element2);
	mlx_destroy_window((*mlx_win)->mlx, (*mlx_win)->win);
	mlx_destroy_display((*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->angle);
	ft_memdel((void **)mlx_win);
	release_rotation_matrix(g_z_rotation_matrix, g_z_is_rotation_matrix);
	release_rotation_matrix(g_y_rotation_matrix, g_y_is_rotation_matrix);
	release_rotation_matrix(g_x_rotation_matrix, g_x_is_rotation_matrix);
	return ;
}
