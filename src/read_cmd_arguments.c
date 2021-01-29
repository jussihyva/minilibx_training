/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:01:55 by juhani            #+#    #+#             */
/*   Updated: 2021/01/29 23:08:21 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ex.h"

t_position	*read_cmd_arguments(int argc, char **argv)
{
	t_position	*angle;
	int			i;

	angle = (t_position *)ft_memalloc(sizeof(*angle));
	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-x"))
		{
			i++;
			angle->x = ft_atoi(argv[i]) % 360;
		}
		else if (ft_strequ(argv[i], "-y"))
		{
			i++;
			angle->y = ft_atoi(argv[i]) % 360;
		}
		if (ft_strequ(argv[i], "-z"))
		{
			i++;
			angle->z = ft_atoi(argv[i]) % 360;
		}
	}
	return (angle);
}
