/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:38:09 by jkauppi           #+#    #+#             */
/*   Updated: 2021/02/07 16:17:13 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void		mlx_image_pixel_put(t_img *img, int x, int y, int color)
{
	char	*img_ptr;

	img_ptr = img->data + (y * img->size_line / 4 +
											x * (img->bpp / 8));
	*(unsigned int *)img_ptr = color;
	return ;
}
