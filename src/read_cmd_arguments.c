/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_cmd_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 21:01:55 by juhani            #+#    #+#             */
/*   Updated: 2021/03/06 23:06:28 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static int				open_fd(char *map_file_path)
{
	int		fd;

	if ((fd = open(map_file_path, O_RDONLY)) == -1)
	{
		ft_printf("%s (%s) failed! errno=%d. %s: %s (File:%s line:%d))\n",
					"Opening of a file", map_file_path, errno, "Detail info",
					strerror(errno), __FILE__, __LINE__);
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

static t_map			*validate_map(char *map_file)
{
	t_map			*map;
	int				fd;
	char			*line;

	map = (t_map *)ft_memalloc(sizeof(*map));
	line = NULL;
	if ((fd = open_fd(map_file)) >= 0)
	{
		ft_printf("Map file path: %s\n", map_file);
		map->map_size =
				(t_xy_values *)ft_memalloc(sizeof(*map->map_size));
		while (ft_get_next_line(fd, &line) > 0)
		{
			ft_printf("Line %3d: %s\n", map->map_size->y, line);
			validate_map_line(line, map->map_size);
			map->map_size->y++;
			ft_strdel(&line);
		}
		ft_strdel(&line);
		ft_printf("Map size: X=%d Y=%d\n", map->map_size->x,
													map->map_size->y);
		close(fd);
	}
	return (map);
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

static t_map			*read_map_file(char *map_file)
{
	t_map			*map;
	int				fd;
	size_t			i;
	char			*line;

	line = NULL;
	map = validate_map(map_file);
	if ((fd = open_fd(map_file)) >= 0)
	{
		map->elem_altitude = (int **)ft_memalloc(sizeof(*map->elem_altitude) *
													map->map_size->y);
		i = -1;
		while (ft_get_next_line(fd, &line) > 0)
		{
			map->elem_altitude[++i] = read_map_values(line,
													map->map_size->x);
			ft_strdel(&line);
		}
		ft_strdel(&line);
		close(fd);
	}
	return (map);
}

t_input					*read_cmd_arguments(int argc, char **argv)
{
	t_input		*input;

	input = (t_input *)ft_memalloc(sizeof(*input));
	input->angle = (t_position *)ft_memalloc(sizeof(*input->angle));
	if ((input->cmd_args = argp_parse(argc, argv)))
	{
		if (input->cmd_args->map_file)
			input->map = read_map_file(input->cmd_args->map_file);
		input->angle->x = input->cmd_args->x % 360;
		input->angle->y = input->cmd_args->y % 360;
		input->angle->z = input->cmd_args->z % 360;
	}
	else
		release_input_data(&input);
	return (input);
}
