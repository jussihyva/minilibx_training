/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemental_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juhani <juhani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:46:08 by juhani            #+#    #+#             */
/*   Updated: 2021/02/01 01:25:52 by juhani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex.h"

static double	d_one(double nbr)
{
	(void)nbr;
	return ((double)1);
}

static double	d_zero(double nbr)
{
	(void)nbr;
	return ((double)0);
}

static double	neg_sin(double nbr)
{
	return (-sin(nbr));
}

static double	**get_z_rotation_matrix(int angle)
{
	static double	(*fn_z_rotation_matrix[3][3])(double) =
													{{cos, neg_sin, d_zero},
													{sin, cos, d_zero},
													{d_zero, d_zero, d_one}};
	double		**rotation_matrix;
	double		radian_angle;
	size_t		i;
	size_t		j;

	radian_angle = RADIAN(angle);
	if (!g_z_is_rotation_matrix[angle])
	{
		g_z_rotation_matrix[angle] =
						(double **)ft_memalloc(sizeof(*rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
			g_z_rotation_matrix[angle][i] =
						(double *)ft_memalloc(sizeof(**rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
				g_z_rotation_matrix[angle][i][j] +=
									(*fn_z_rotation_matrix[i][j])(radian_angle);
		}
		g_z_is_rotation_matrix[angle] = 1;
	}
	rotation_matrix = g_z_rotation_matrix[angle];
	return (rotation_matrix);
}

static double	**get_y_rotation_matrix(int angle)
{
	static double	(*fn_y_rotation_matrix[3][3])(double) =
													{{cos, d_zero, sin},
													{d_zero, d_one, d_zero},
													{neg_sin, d_zero, cos}};
	double		**rotation_matrix;
	double		radian_angle;
	size_t		i;
	size_t		j;

	if (!g_y_is_rotation_matrix[angle])
	{
		radian_angle = RADIAN(angle);
		g_y_rotation_matrix[angle] =
						(double **)ft_memalloc(sizeof(*rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
			g_y_rotation_matrix[angle][i] =
						(double *)ft_memalloc(sizeof(**rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
				g_y_rotation_matrix[angle][i][j] +=
									(*fn_y_rotation_matrix[i][j])(radian_angle);
		}
		g_y_is_rotation_matrix[angle] = 1;
	}
	rotation_matrix = g_y_rotation_matrix[angle];
	return (rotation_matrix);
}

static double	**get_x_rotation_matrix(int angle)
{
	static double	(*fn_x_rotation_matrix[3][3])(double) =
													{{d_one, d_zero, d_zero},
													{d_zero, cos, neg_sin},
													{d_zero, sin, cos}};
	double		**rotation_matrix;
	double		radian_angle;
	size_t		i;
	size_t		j;

	if (!g_x_is_rotation_matrix[angle])
	{
		radian_angle = RADIAN(angle);
		g_x_rotation_matrix[angle] =
						(double **)ft_memalloc(sizeof(*rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
			g_x_rotation_matrix[angle][i] =
						(double *)ft_memalloc(sizeof(**rotation_matrix) * 3);
		i = -1;
		while (++i < 3)
		{
			j = -1;
			while (++j < 3)
				g_x_rotation_matrix[angle][i][j] +=
									(*fn_x_rotation_matrix[i][j])(radian_angle);
		}
		g_x_is_rotation_matrix[angle] = 1;
	}
	rotation_matrix = g_x_rotation_matrix[angle];
	return (rotation_matrix);
}

static void		matrix_vector_multiply(double **matrix, double *vector,
															double *new_vector)
{
	size_t			i;
	size_t			j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		new_vector[i] = 0;
		while (++j < 3)
			new_vector[i] += matrix[i][j] * vector[j];
	}
	return ;
}

static void		rotation(t_position *elem_position, t_position *angle)
{
	double			elem_position_vector[3];
	double			new_elem_position_vector[3];
	double			**rotation_matrix;

	elem_position_vector[0] = elem_position->x;
	elem_position_vector[1] = elem_position->y;
	elem_position_vector[2] = elem_position->z;
	rotation_matrix = get_z_rotation_matrix(angle->x);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position_vector[0] = new_elem_position_vector[0];
	elem_position_vector[1] = new_elem_position_vector[1];
	elem_position_vector[2] = new_elem_position_vector[2];

	rotation_matrix = get_y_rotation_matrix(angle->z);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position_vector[0] = new_elem_position_vector[0];
	elem_position_vector[1] = new_elem_position_vector[1];
	elem_position_vector[2] = new_elem_position_vector[2];

	rotation_matrix = get_x_rotation_matrix(angle->y);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position->x = (int)(new_elem_position_vector[0] + 0.5);
	elem_position->y = (int)(new_elem_position_vector[1] + 0.5);
	elem_position->z = (int)(new_elem_position_vector[2] + 0.5);
	return ;
}

void			elemental_rotation(t_element *element)
{
	size_t		i;
	t_position	*position_offset;
	t_position	*elem_positions;
	t_position	*angle;

	ft_memcpy(element->elem_positions, element->elem_start_positions,
				sizeof(*element->elem_start_positions) * NUM_OF_ELEM_POSITIONS);
	elem_positions = element->elem_positions;
	position_offset = &element->elem_position_offset;
	ft_bzero(position_offset, sizeof(*position_offset));
	angle = element->angle;
	ft_printf("ANGLE: X=%d Y=%d Z=%d\n", angle->x, angle->y, angle->z);
	i = -1;
	while (++i < NUM_OF_ELEM_POSITIONS)
	{
		rotation(&(elem_positions[i]), angle);
		position_offset->x = MAX(position_offset->x, -elem_positions[i].x);
		position_offset->y = MAX(position_offset->y, -elem_positions[i].y);
		position_offset->z = MAX(position_offset->z, -elem_positions[i].z);
	}
	return ;
}
