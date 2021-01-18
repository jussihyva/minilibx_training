/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_pixel_put.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 03:38:09 by jkauppi           #+#    #+#             */
/*   Updated: 2021/01/18 03:50:20 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void		mlx_image_pixel_put(t_element *element, int x, int y, int color)
{
	char	*img_ptr;

	img_ptr = element->addr + (y * element->line_length +
											x * (element->bits_per_pixel / 8));
	*(unsigned int *)img_ptr = color;
	return ;
}
