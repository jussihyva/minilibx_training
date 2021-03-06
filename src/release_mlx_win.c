/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:41:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/06 23:06:01 by jkauppi          ###   ########.fr       */
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

static void		release_element(t_element **element)
{
	if (*element)
	{
		ft_memdel((void **)&(*element)->elem_positions);
		ft_memdel((void **)&(*element)->elem_start_positions);
		ft_memdel((void **)&(*element)->elem_lines);
		ft_memdel((void **)&(*element)->angle);
		ft_memdel((void **)element);
	}
	return ;
}

static void		release_element_map(t_element ***element_map,
												t_xy_values *element_map_size)
{
	int		i;
	int		j;

	i = -1;
	while (++i < element_map_size->y)
	{
		j = -1;
		while (++j < element_map_size->x)
			release_element(&element_map[i][j]);
		ft_memdel((void **)&element_map[i]);
	}
	ft_memdel((void **)&element_map);
	return ;
}

void			release_mlx_win(t_mlx_win **mlx_win)
{
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->img);
	ft_memdel((void **)&(*mlx_win)->element1->start_position);
	release_element(&(*mlx_win)->element1);
	release_element(&(*mlx_win)->element2);
	release_element_map((*mlx_win)->element_map, (*mlx_win)->element_map_size);
	mlx_destroy_window((*mlx_win)->mlx, (*mlx_win)->win);
	mlx_destroy_display((*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->img_start_position);
	ft_memdel((void **)&(*mlx_win)->first_elem_start_position);
	ft_memdel((void **)mlx_win);
	release_rotation_matrix(g_z_rotation_matrix, g_z_is_rotation_matrix);
	release_rotation_matrix(g_y_rotation_matrix, g_y_is_rotation_matrix);
	release_rotation_matrix(g_x_rotation_matrix, g_x_is_rotation_matrix);
	return ;
}

void			release_input_data(t_input **input)
{
	int			i;

	i = -1;
	if ((*input)->map)
	{
		while (++i < (*input)->map->map_size->y)
		{
			ft_memdel((void **)&(*input)->map->elem_altitude[i]);
		}
		ft_memdel((void **)&(*input)->map->elem_altitude);
		ft_memdel((void **)&(*input)->map->map_size);
		ft_memdel((void **)&(*input)->map);
	}
	ft_memdel((void **)&(*input)->cmd_args);
	ft_memdel((void **)&(*input)->angle);
	ft_memdel((void **)input);
	return ;
}
