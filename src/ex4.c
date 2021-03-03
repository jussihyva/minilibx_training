/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 04:03:20 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/10 14:10:46 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static t_element		***create_element_map(t_mlx_win *mlx_win,
												t_map_file_data *map_file_data)
{
	t_element		***element_map;
	t_position		*elem_start_position;
	t_position		elem_size;
	t_position		*position_offset;
	int				i;
	int				j;

	mlx_win->first_elem_start_position =
			(t_position *)ft_memalloc(sizeof(*mlx_win->first_elem_start_position));
	set_position(mlx_win->first_elem_start_position, 0, 0, 0);
	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	set_position(&elem_size, 50, 50, 0);
	element_map = (t_element ***)ft_memalloc(sizeof(*element_map) *
													map_file_data->map_size->y);
	i = -1;
	elem_start_position = mlx_win->first_elem_start_position;
	while (++i < map_file_data->map_size->y)
	{
		element_map[i] = (t_element **)ft_memalloc(sizeof(*element_map[i]) *
													map_file_data->map_size->x);
		j = -1;
		while (++j < map_file_data->map_size->x)
		{
			element_map[i][j] = create_element(mlx_win, elem_start_position,
												position_offset, &elem_size);
			elem_start_position = &element_map[i][j]->elem_positions[1];
		}
		elem_start_position = &element_map[i][0]->elem_positions[2];
	}
	ft_memdel((void **)&position_offset);
	return (element_map);
}

int				main(int argc, char **argv)
{
	t_mlx_win			*mlx_win;
	t_position			*elem_start_position;
	t_position			elem_size;
	t_position			*position_offset;
	t_xy_values			img_size;
	t_input				*input;
	int					**map;
	int					i;
	int					j;

	elem_start_position =
						(t_position *)ft_memalloc(sizeof(*elem_start_position));
	position_offset = (t_position *)ft_memalloc(sizeof(*position_offset));
	img_size.x = 600;
	img_size.y = 600;
	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->img_start_position =
				(t_position *)ft_memalloc(sizeof(*mlx_win->img_start_position));
	mlx_win->render_action = e_no_action;
	input = read_cmd_arguments(argc, argv);
	mlx_win->angle = input->angle;
	mlx_win->angle_step = 5;
	map = input->map_file_data->map;
	mlx_win->element_map = create_element_map(mlx_win, input->map_file_data);
	mlx_win->element_map_size = input->map_file_data->map_size;
	i = -1;
	while (++i < input->map_file_data->map_size->y)
	{
		j = -1;
		while (++j < input->map_file_data->map_size->x)
			ft_printf(" %3d", map[i][j]);
		ft_printf("\n");
	}
	mlx_win->mlx = mlx_init();
	initialize_window(mlx_win, "Minilibx training 4 (ex4)");
	mlx_win->empty_img = mlx_new_image(mlx_win->mlx, img_size.x, img_size.y);
	mlx_win->img = mlx_new_image(mlx_win->mlx, img_size.x, img_size.y);
	set_position(elem_start_position, 0, 0, 0);
	set_position(&elem_size, 50, 50, 0);
	mlx_win->element1 = create_element(mlx_win, elem_start_position,
												position_offset, &elem_size);
	ft_memcpy(mlx_win->img_start_position, elem_start_position,
										sizeof(*mlx_win->img_start_position));
	ft_printf("Start X: %d\n", mlx_win->element1->elem_positions[1].x);
	ft_printf("Start Y: %d\n", mlx_win->element1->elem_positions[1].y);
	ft_printf("Start Z: %d\n", mlx_win->element1->elem_positions[1].z);
	elem_start_position = &mlx_win->element1->elem_positions[1];
	set_position(&elem_size, 50, 50, 50);
	mlx_win->element2 = create_element(mlx_win, elem_start_position,
												position_offset, &elem_size);
	mlx_win->element1->elem_position_offset.x = position_offset->x;
	mlx_win->element1->elem_position_offset.y = position_offset->y;
	mlx_win->element2->elem_position_offset.x = position_offset->x +
										mlx_win->element1->elem_positions[1].x;
	mlx_win->element2->elem_position_offset.y = position_offset->y +
										mlx_win->element1->elem_positions[1].y;
	draw_lines(mlx_win->img, mlx_win->element1);
	draw_lines(mlx_win->img, mlx_win->element2);
	mlx_win->render_action = e_put_image_to_window;
	mlx_loop_hook(mlx_win->mlx, render_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	release_input_data(&input);
	ft_memdel((void **)&position_offset);
	return (0);
}
