/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_radian.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 08:08:39 by juhani            #+#    #+#             */
/*   Updated: 2021/02/07 08:11:43 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

double		ft_radian(double angle_degree)
{
	double	angle_rad;

	angle_rad = angle_degree * PI / 180;
	return (angle_rad);
}
