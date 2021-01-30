/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:30:23 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/30 21:29:18 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_H
# define EX_H
# include "mlx.h"
# include "ft_printf.h"
# include <math.h>

# define PI							3.141592654
# define NUM_OF_ELEM_POSITIONS		8
# define RADIAN(x)					x * PI / 180
# define MAX(x,y)					(x > y) ? x : y

double	**g_z_rotation_matrix[360];
int		g_z_is_rotation_matrix[360];
double	**g_y_rotation_matrix[360];
int		g_y_is_rotation_matrix[360];
double	**g_x_rotation_matrix[360];
int		g_x_is_rotation_matrix[360];

typedef struct	s_position
{
	int			x;
	int			y;
	int			z;
}				t_position;

typedef enum	e_render_action
{
	e_no_action,
	e_put_image_to_window
}				t_render_action;

typedef struct	s_elem_size
{
	int			x;
	int			y;
	int			z;
}				t_elem_size;

typedef struct	s_elem_line
{
	t_position	*start;
	t_position	*end;
}				t_elem_line;

typedef struct	s_element
{
	t_elem_size	*elem_size;
	t_position	*angle;
	t_position	*elem_positions;
	t_position	*elem_start_positions;
	t_position	elem_position_offset;
	t_elem_line	*elem_lines;
	void		*empty_img;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_position	start_position;
	t_position	current_position;
	t_position	next_position;
}				t_element;

typedef struct	s_mlx_win
{
	void				*mlx;
	void				*win;
	t_element			*element1;
	t_element			*element2;
	t_render_action		render_action;
}				t_mlx_win;

int				close_win(t_mlx_win *mlx_win);
int				button_press(int keycode, int x, int y, t_mlx_win *mlx_win);
int				key_press(int keycode, t_mlx_win *mlx_win);
int				motion_notify(int x, int y, t_mlx_win *mlx_win);
int				enter_notify(t_mlx_win *mlx_win);
int				leave_notify(t_mlx_win *mlx_win);
void			release_mlx_win(t_mlx_win **mlx_win);
int				render_frame(t_mlx_win *mlx_win);
t_element		*create_element(t_mlx_win *mlx_win, t_position *start_position,
															t_position *angle);
void			mlx_image_pixel_put(t_element *element, int x, int y,
																	int color);
void			initialize_window(t_mlx_win *mlx_win, char *window_name);
t_position		*set_elem_positions(t_elem_size *elem_size);
void			z_elemental_rotation(t_element *element);
void			draw_lines(t_element *element);
void			set_position(t_position *position, int x, int y, int z);
t_position		*read_cmd_arguments(int argc, char **argv);

#endif
