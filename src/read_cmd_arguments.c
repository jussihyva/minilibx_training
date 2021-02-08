/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:01:55 by juhani            #+#    #+#             */
/*   Updated: 2021/02/08 08:15:08 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int		open_fd(char *map_file_path)
{
	int		fd;

	fd = open(map_file_path, O_RDONLY);
	return (fd);
}

static void		read_map_file(char *map_file_path)
{
	int				ret;
	char			*line;
	char			**map_char_array;
	int				fd;
	int				i;
	t_xy_values		map_size;

	line = NULL;
	map_size.x = 0;
	map_size.y = 0;
	ft_printf("Map file path: %s\n", map_file_path);
	if ((fd = open_fd(map_file_path)) >= 0)
	{
		while ((ret = ft_get_next_line(fd, &line)) > 0)
		{
			map_char_array = ft_strsplit(line, ' ');
			ft_printf("Line: ");
			i = 0;
			while (map_char_array[i])
			{
				ft_printf(" %2s ", map_char_array[i]);
				i++;
			}
			ft_printf("\n");
			if (map_size.x == 0)
				map_size.x = i;
			else
			{
				if (map_size.x != i)
					exit(42);
			}
			map_size.y++;
			ft_strdel(&line);
		}
		ft_printf("Map size: X=%d Y=%d\n", map_size.x, map_size.y);
		ft_strdel(&line);
	}
	return ;
}

t_position		*read_cmd_arguments(int argc, char **argv)
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
		else if (ft_strequ(argv[i], "-z"))
		{
			i++;
			angle->z = ft_atoi(argv[i]) % 360;
		}
		else if (ft_strequ(argv[i], "-f"))
		{
			i++;
			if (i < argc)
				read_map_file(argv[i]);
		}
	}
	return (angle);
}
