/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elemental_rotation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkauppi <jkauppi@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:46:08 by juhani            #+#    #+#             */
/*   Updated: 2021/03/07 10:36:58 by jkauppi          ###   ########.fr       */
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

static double	(*g_fn_z_rotation_matrix[3][3])(double) =
{
	{cos, neg_sin, d_zero},
	{sin, cos, d_zero},
	{d_zero, d_zero, d_one}
};

static double	(*g_fn_y_rotation_matrix[3][3])(double) =
{
	{cos, d_zero, sin},
	{d_zero, d_one, d_zero},
	{neg_sin, d_zero, cos}
};

static double	(*g_fn_x_rotation_matrix[3][3])(double) =
{
	{d_one, d_zero, d_zero},
	{d_zero, cos, neg_sin},
	{d_zero, sin, cos}
};

static double	**initialize_rotation_matrix(double radian_angle,
									double (*fn_rotation_matrix[3][3])(double))
{
	double		**rotation_matrix;
	size_t		i;
	size_t		j;

	rotation_matrix = (double **)ft_memalloc(sizeof(*rotation_matrix) * 3);
	i = -1;
	while (++i < 3)
		rotation_matrix[i] =
					(double *)ft_memalloc(sizeof(**rotation_matrix) * 3);
	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			rotation_matrix[i][j] +=
								(*fn_rotation_matrix[i][j])(radian_angle);
	}
	return (rotation_matrix);
}

static double	**get_z_rotation_matrix(int angle)
{
	double		**rotation_matrix;
	double		radian_angle;

	radian_angle = ft_radian(angle);
	if (!g_z_is_rotation_matrix[angle])
	{
		g_z_rotation_matrix[angle] = initialize_rotation_matrix(radian_angle,
														g_fn_z_rotation_matrix);
		g_z_is_rotation_matrix[angle] = 1;
	}
	rotation_matrix = g_z_rotation_matrix[angle];
	return (rotation_matrix);
}

static double	**get_y_rotation_matrix(int angle)
{
	double		**rotation_matrix;
	double		radian_angle;

	if (!g_y_is_rotation_matrix[angle])
	{
		radian_angle = ft_radian(angle);
		g_y_rotation_matrix[angle] = initialize_rotation_matrix(radian_angle,
														g_fn_y_rotation_matrix);
		g_y_is_rotation_matrix[angle] = 1;
	}
	rotation_matrix = g_y_rotation_matrix[angle];
	return (rotation_matrix);
}

static double	**get_x_rotation_matrix(int angle)
{
	double		**rotation_matrix;
	double		radian_angle;

	if (!g_x_is_rotation_matrix[angle])
	{
		radian_angle = ft_radian(angle);
		g_x_rotation_matrix[angle] = initialize_rotation_matrix(radian_angle,
														g_fn_x_rotation_matrix);
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
	rotation_matrix = get_z_rotation_matrix(angle->z);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position_vector[0] = new_elem_position_vector[0];
	elem_position_vector[1] = new_elem_position_vector[1];
	elem_position_vector[2] = new_elem_position_vector[2];
	rotation_matrix = get_y_rotation_matrix(angle->y);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position_vector[0] = new_elem_position_vector[0];
	elem_position_vector[1] = new_elem_position_vector[1];
	elem_position_vector[2] = new_elem_position_vector[2];
	rotation_matrix = get_x_rotation_matrix(angle->x);
	matrix_vector_multiply(rotation_matrix, elem_position_vector,
													new_elem_position_vector);
	elem_position->x = (int)(new_elem_position_vector[0] + 0.5);
	elem_position->y = (int)(new_elem_position_vector[1] + 0.5);
	elem_position->z = (int)(new_elem_position_vector[2] + 0.5);
}

static size_t	line_len(t_position *elem_position1, t_position *elem_position2)
{
	double		len;

	len = sqrt(pow(elem_position1->x - elem_position2->x, 2) +
				pow(elem_position1->y - elem_position2->y, 2));
	return ((size_t)len);
}

static void		print_element_data(t_element *element, t_position *angle)
{
	t_position	*positions;
	size_t		size54;
	size_t		size57;
	size_t		size51;

	(void)angle;
	positions = element->current_positions;
	size54 = line_len(&positions[5], &positions[4]);
	size57 = line_len(&positions[7], &positions[5]);
	size51 = line_len(&positions[1], &positions[5]);
	// ft_printf("ANGLE: X=%3d(%3d) Y=%3d(%3d) Z=%3d(%3d)",
	// 												angle->x, angle->x - 360,
	// 												angle->y, angle->y - 360,
	// 												angle->z, angle->z - 360);
	// ft_printf("SIZE: 5_4=%u 5_7=%u 5_1=%u\n", size54, size57, size51);
	return ;
}

void			elemental_rotation(t_element *element, t_position *angle,
						t_position *position_offset, t_position *start_position)
{
	size_t		i;
	t_position	*current_positions;

	ft_memcpy(element->current_positions, element->start_positions,
				sizeof(*element->start_positions) * NUM_OF_ELEM_POSITIONS);
	current_positions = element->current_positions;
	i = -1;
	while (++i < NUM_OF_ELEM_POSITIONS)
	{
		rotation(&(current_positions[i]), angle);
		position_offset->x = ft_max_int(position_offset->x,
														-(current_positions[i].x +
														start_position->x));
		position_offset->y = ft_max_int(position_offset->y,
														-(current_positions[i].y +
														start_position->y));
		position_offset->z = ft_max_int(position_offset->z,
														-(current_positions[i].z +
														start_position->z));
	}
	print_element_data(element, angle);
	return ;
}
