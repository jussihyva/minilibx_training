/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   release_mlx_win.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 19:41:05 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/17 19:43:20 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void	release_mlx_win(t_mlx_win **mlx_win)
{
	ft_memdel((void **)&(*mlx_win)->img);
	ft_memdel((void **)&(*mlx_win)->mlx);
	ft_memdel((void **)mlx_win);
	return ;
}