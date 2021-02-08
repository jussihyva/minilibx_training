/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:01:55 by juhani            #+#    #+#             */
/*   Updated: 2021/02/08 13:23:00 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int				open_fd(char *map_file_path)
{
	int		fd;

	if ((fd = open(map_file_path, O_RDONLY)) == -1)
	{
		ft_printf("Opening of a file (%s) failed! errno=%d. Detail info: %s\n",
										map_file_path, errno, strerror(errno));
		exit(42);
	}
	return (fd);
}

static void				validate_map_line(char *line, t_xy_values *map_size)
{
	char			**char_array;
	int				i;

	i = -1;
	char_array = ft_strsplit(line, ' ');
	while (char_array[++i])
	{
		ft_strdel(&char_array[i]);
	}
	ft_memdel((void **)&char_array);
	if (map_size->x == 0)
		map_size->x = i;
	else
	{
		if (map_size->x != i)
		{
			ft_printf("%s %s %d and %d.\n",
						"ERROR: Variable num of numbers in map lines. ",
						"Compare lines ",
						map_size->y,
						map_size->y + 1);
			exit(42);
		}
	}
	return ;
}

static t_map_file_data	*validate_map(char *map_file_path)
{
	t_map_file_data		*map_file_data;
	int					fd;
	char				*line;

	map_file_data = (t_map_file_data *)ft_memalloc(sizeof(*map_file_data));
	line = NULL;
	if ((fd = open_fd(map_file_path)) >= 0)
	{
		ft_printf("Map file path: %s\n", map_file_path);
		map_file_data->map_size =
				(t_xy_values *)ft_memalloc(sizeof(*map_file_data->map_size));
		while (ft_get_next_line(fd, &line) > 0)
		{
			ft_printf("Line %3d: %s\n", map_file_data->map_size->y, line);
			validate_map_line(line, map_file_data->map_size);
			map_file_data->map_size->y++;
			ft_strdel(&line);
		}
		ft_strdel(&line);
		ft_printf("Map size: X=%d Y=%d\n", map_file_data->map_size->x,
													map_file_data->map_size->y);
		close(fd);
	}
	return (map_file_data);
}

static int				*read_map_values(char *line, int size)
{
	int				*array;
	char			**char_array;
	int				i;
	char			*endptr;

	array = (int *)ft_memalloc(sizeof(*array) * size);
	i = -1;
	char_array = ft_strsplit(line, ' ');
	while (++i < size)
	{
		array[i] = ft_strtoi(char_array[i], &endptr, 10);
		ft_strdel(&char_array[i]);
	}
	ft_memdel((void **)&char_array);
	return (array);
}

static t_map_file_data	*read_map_file(char *map_file_path)
{
	t_map_file_data		*map_file_data;
	int					fd;
	size_t				i;
	char				*line;

	line = NULL;
	map_file_data = validate_map(map_file_path);
	if ((fd = open_fd(map_file_path)) >= 0)
	{
		map_file_data->map = (int **)ft_memalloc(sizeof(*map_file_data->map) *
													map_file_data->map_size->y);
		i = -1;
		while (ft_get_next_line(fd, &line) > 0)
		{
			map_file_data->map[++i] = read_map_values(line,
													map_file_data->map_size->x);
			ft_strdel(&line);
		}
		ft_strdel(&line);
		close(fd);
	}
	return (map_file_data);
}

t_input					*read_cmd_arguments(int argc, char **argv)
{
	t_input		*input;
	int			i;

	input = (t_input *)ft_memalloc(sizeof(*input));
	input->angle = (t_position *)ft_memalloc(sizeof(*input->angle));
	i = 0;
	while (++i < argc)
	{
		if (ft_strequ(argv[i], "-x"))
		{
			i++;
			input->angle->x = ft_atoi(argv[i]) % 360;
		}
		else if (ft_strequ(argv[i], "-y"))
		{
			i++;
			input->angle->y = ft_atoi(argv[i]) % 360;
		}
		else if (ft_strequ(argv[i], "-z"))
		{
			i++;
			input->angle->z = ft_atoi(argv[i]) % 360;
		}
		else if (ft_strequ(argv[i], "-f"))
		{
			i++;
			if (i < argc)
				input->map_file_data = read_map_file(argv[i]);
		}
	}
	return (input);
}
