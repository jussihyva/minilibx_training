/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:43:15 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/07 15:43:39 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

void			print_start_position(t_position *elem_start_position)
{
	ft_printf("Start postition: x= %d, y=%d, z=%d\n", elem_start_position->x,
								elem_start_position->y, elem_start_position->z);
	return ;
}

