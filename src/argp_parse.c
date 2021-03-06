/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argp_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/06 18:28:12 by jkauppi           #+#    #+#             */
/*   Updated: 2021/03/06 23:12:08 by jkauppi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static void		save_args(t_cmd_args *cmd_args, char *arg, char *arg_next,
																		int *i)
{
	char		opt;
	int			j;

	j = 0;
	while ((opt = arg[++j]))
	{
		if (ft_strchr("fPxyz", opt))
		{
			if (opt == 'f')
				cmd_args->map_file = arg_next;
			else if (opt == 'P')
				cmd_args->projection_type = ft_atoi(arg_next);
			else if (opt == 'x')
				cmd_args->x = ft_atoi(arg_next);
			else if (opt == 'y')
				cmd_args->y = ft_atoi(arg_next);
			else if (opt == 'z')
				cmd_args->z = ft_atoi(arg_next);
			++(*i);
			break ;
		}
		else
			ft_printf("-%c\n", opt);
	}
	return ;
}

static int		unknown_parameter(const char *s)
{
	printf("Unknown optional parameter: %s\n", s);
	return (0);
}

t_cmd_args		*argp_parse(int argc, char **argv)
{
	t_cmd_args			*cmd_args;
	int					i;
	int					are_param_valid;

	cmd_args = (t_cmd_args *)ft_memalloc(sizeof(*cmd_args));
	are_param_valid = 1;
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-')
			save_args(cmd_args, argv[i], argv[i + 1], &i);
		else
			are_param_valid = unknown_parameter(argv[i]);
	}
	if (!are_param_valid)
		ft_memdel((void **)&cmd_args);
	return (cmd_args);
}
