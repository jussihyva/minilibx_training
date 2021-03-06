/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:30:23 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/09 13:31:25 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_H
# define EX_H
# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"
# include "libft_addons.h"
# include "ft_printf.h"
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define NUM_OF_ELEM_POSITIONS		8

double	**g_z_rotation_matrix[360];
int		g_z_is_rotation_matrix[360];
double	**g_y_rotation_matrix[360];
int		g_y_is_rotation_matrix[360];
double	**g_x_rotation_matrix[360];
int		g_x_is_rotation_matrix[360];

typedef struct	s_cmd_args
{
	char		*map_file;
	size_t		projection_type;
	int			x;
	int			y;
	int			z;
	int			elem_side_len;
}				t_cmd_args;

typedef struct	s_matrix_size
{
	int			rows;
	int			columns;
}				t_matrix_size;

typedef struct	s_xy_values
{
	int			x;
	int			y;
}				t_xy_values;

typedef struct	s_map
{
	int				**elem_altitude;
	int				max_altitude;
	int				min_altitude;
	t_xy_values		*map_size;

}				t_map;

typedef struct	s_position
{
	int			x;
	int			y;
	int			z;
}				t_position;

typedef struct	s_position_new
{
	double		x;
	double		y;
	double		z;
}				t_position_new;

typedef struct	s_input
{
	t_cmd_args		*cmd_args;
	t_map			*map;
	t_position		*angle;
}				t_input;

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
	int			color;
	int			line_type;
}				t_elem_line;

typedef struct	s_drawing_data
{
	unsigned int	color;
	int				size_line;
	t_position		start;
	t_position		end;
	int				line_type;
}				t_drawing_data;

typedef struct	s_element
{
	t_elem_size	elem_size;
	t_position	*angle;
	t_position	*current_positions;
	t_position	*start_positions;
	t_position	elem_position_offset;
	t_elem_line	*elem_lines;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_position	*start_position;
}				t_element;

typedef struct	s_mlx_win
{
	void				*mlx;
	void				*win;
	t_element			***elem_table;
	t_position			*first_elem_start_position;
	t_element			***element_map;
	t_xy_values			*element_map_size;
	t_position			*angle;
	int					angle_step;
	t_img				*img;
	t_position			*img_start_position;
	t_img				*empty_img;
	t_xy_values			img_size;
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
							t_position *position_offset, t_position *elem_size);
void			mlx_image_pixel_put(t_img *img, int x, int y, int color);
void			initialize_window(t_mlx_win *mlx_win, char *window_name);
t_position		*set_elem_positions(t_elem_size *elem_size);
void			elemental_rotation(t_element *element, t_position *angle,
					t_position *position_offset, t_position *start_position);
void			draw_lines(t_img *img, t_element *element);
void			set_position(t_position *position, int x, int y, int z);
t_input			*read_cmd_arguments(int argc, char **argv);
void			bresenham_draw_line(t_img *img, t_elem_line *line,
											t_position *elem_position_offset);
void			release_input_data(t_input **input);
t_cmd_args		*argp_parse(int argc, char **argv);
void			print_start_position(t_position *elem_start_position);

#endif
