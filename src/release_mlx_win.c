/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:41:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 05:33:03 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	release_mlx_win(t_mlx_win **mlx_win)
{
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element->img);
	ft_memdel((void **)&(*mlx_win)->element->elem_size);
	ft_memdel((void **)&(*mlx_win)->element->elem_positions);
	ft_memdel((void **)&(*mlx_win)->element->elem_lines);
	ft_memdel((void **)&(*mlx_win)->element);
	mlx_destroy_window((*mlx_win)->mlx, (*mlx_win)->win);
	mlx_destroy_display((*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->mlx);
	ft_memdel((void **)mlx_win);
	return ;
}
