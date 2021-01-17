/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 10:30:23 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 19:43:37 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_H
# define EX_H
# include "mlx.h"
# include "ft_printf.h"

typedef struct	s_mlx_win
{
	void		*mlx;
	void		*win;
	void		*img;
}				t_mlx_win;

int				close_win(t_mlx_win *mlx_win);
int				key_press(int keycode, t_mlx_win *mlx_win);
int				motion_notify(int x, int y, t_mlx_win *mlx_win);
int				enter_notify(t_mlx_win *mlx_win);
int				leave_notify(t_mlx_win *mlx_win);
void			release_mlx_win(t_mlx_win **mlx_win);

#endif
