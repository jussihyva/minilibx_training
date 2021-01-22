/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:41:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/22 12:18:03 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	release_mlx_win(t_mlx_win **mlx_win)
{
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element1->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element1->img);
	ft_memdel((void **)&(*mlx_win)->element1->elem_size);
	ft_memdel((void **)&(*mlx_win)->element1->elem_positions);
	ft_memdel((void **)&(*mlx_win)->element1->elem_lines);
	ft_memdel((void **)&(*mlx_win)->element1);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element2->empty_img);
	mlx_destroy_image((*mlx_win)->mlx, (*mlx_win)->element2->img);
	ft_memdel((void **)&(*mlx_win)->element2->elem_size);
	ft_memdel((void **)&(*mlx_win)->element2->elem_positions);
	ft_memdel((void **)&(*mlx_win)->element2->elem_lines);
	ft_memdel((void **)&(*mlx_win)->element2);
	mlx_destroy_window((*mlx_win)->mlx, (*mlx_win)->win);
	mlx_destroy_display((*mlx_win)->mlx);
	ft_memdel((void **)&(*mlx_win)->mlx);
	ft_memdel((void **)mlx_win);
	return ;
}
