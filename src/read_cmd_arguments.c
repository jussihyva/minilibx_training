/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:01:55 by juhani            #+#    #+#             */
/*   Updated: 2021/01/29 21:05:24 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ex.h"

t_position	*read_cmd_arguments(int argc, char **argv)
{
	t_position	*degree;
	int			i;

	degree = (t_position *)ft_memalloc(sizeof(*degree));
	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-x"))
		{
			i++;
			degree->x = RADIAN(ft_atoi(argv[i]));
		}
		else if (ft_strequ(argv[i], "-y"))
		{
			i++;
			degree->y = RADIAN(ft_atoi(argv[i]));
		}
		if (ft_strequ(argv[i], "-z"))
		{
			i++;
			degree->z = RADIAN(ft_atoi(argv[i]));
		}
	}
	return (degree);
}
