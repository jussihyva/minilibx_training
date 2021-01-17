/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:33:41 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 21:00:06 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int		render_next_frame(t_mlx_win *mlx_win)
{
	static int		cnt = 0;

	cnt++;
	if (mlx_win->render_action == e_put_image_to_window)
	{
		ft_printf("Frame rendering function call: %d!\n", cnt);
		mlx_put_image_to_window(mlx_win->mlx, mlx_win->win,
												mlx_win->image->img, 20, 20);
		mlx_win->render_action = e_no_action;
	}
	return (0);
}

static void		initialize_win(t_mlx_win *mlx_win)
{
	mlx_win->win = mlx_new_window(mlx_win->mlx, 1920, 1080,
												"Minilibx training 3 (ex3)");
	mlx_hook(mlx_win->win, 2, 0x01, key_press, mlx_win);
	mlx_hook(mlx_win->win, 4, 0x04, key_press, mlx_win);
	mlx_hook(mlx_win->win, 6, 0x40, motion_notify, mlx_win);
	mlx_hook(mlx_win->win, 7, 0x10, enter_notify, mlx_win);
	mlx_hook(mlx_win->win, 8, 0x20, leave_notify, mlx_win);
	mlx_hook(mlx_win->win, 33, 0x00, close_win, mlx_win);
	return ;
}

static void		img_mlx_pixel_put(t_image *image, int x, int y, int color)
{
	char	*img_ptr;

	img_ptr = image->addr + (y * image->line_length +
											x * (image->bits_per_pixel / 8));
	*(unsigned int *)img_ptr = color;
	return ;
}

static t_image	*create_img(t_mlx_win *mlx_win)
{
	t_image		*image;
	int			i;

	image = (t_image *)ft_memalloc(sizeof(*image));
	image->img = mlx_new_image(mlx_win->mlx, 10, 10);
	image->addr = mlx_get_data_addr(image->img, &(image->bits_per_pixel),
										&(image->line_length), &(image->endian));
	i = -1;
	while (++i < 10)
		img_mlx_pixel_put(image, i, i, 0x00FF0000);
	mlx_win->render_action = e_put_image_to_window;
	return (image);
}

int				main(void)
{
	t_mlx_win	*mlx_win;

	mlx_win = (t_mlx_win *)ft_memalloc(sizeof(*mlx_win));
	mlx_win->render_action = e_no_action;
	mlx_win->mlx = mlx_init();
	initialize_win(mlx_win);
	mlx_win->image = create_img(mlx_win);
	mlx_loop_hook(mlx_win->mlx, render_next_frame, mlx_win);
	mlx_loop(mlx_win->mlx);
	release_mlx_win(&mlx_win);
	return (0);
}
