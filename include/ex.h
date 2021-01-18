/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:30:23 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 05:19:11 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_H
# define EX_H
# include "mlx.h"
# include "ft_printf.h"

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
	t_position	*elem_positions;
	t_elem_line	*elem_lines;
	void		*empty_img;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	t_position	current_position;
	t_position	next_position;
}				t_element;

typedef struct	s_mlx_win
{
	void				*mlx;
	void				*win;
	t_element			*element;
	t_render_action		render_action;
}				t_mlx_win;

int				close_win(t_mlx_win *mlx_win);
int				key_press(int keycode, t_mlx_win *mlx_win);
int				motion_notify(int x, int y, t_mlx_win *mlx_win);
int				enter_notify(t_mlx_win *mlx_win);
int				leave_notify(t_mlx_win *mlx_win);
void			release_mlx_win(t_mlx_win **mlx_win);
int				render_frame(t_mlx_win *mlx_win);
t_element		*create_element(t_mlx_win *mlx_win);
void			mlx_image_pixel_put(t_element *element, int x, int y,
																	int color);
void			initialize_window(t_mlx_win *mlx_win, char *window_name);
t_position		*set_elem_positions(t_elem_size *elem_size);

#endif
