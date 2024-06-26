/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:44:29 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/26 12:31:42 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	get_polar_angle(t_vec orientation, char axis);

void	print_matrix(t_matrix *matrix)
{
	int	col_idx;
	int	row_idx;

	col_idx = 0;
	row_idx = 0;
	while (row_idx < matrix->row_dimension)
	{
		while (col_idx < matrix->column_dimension)
		{
			printf("%f ", get_matrix_item(matrix, row_idx, col_idx));
			col_idx++;
		}
		printf("\n");
		col_idx = 0;
		row_idx++;
	}
	printf("\n");
}

t_matrix	*construct_basic_matrix(t_point translation, \
			t_vec orientation, char axis)
{
	const double	phi = atan2(orientation.x, orientation.z);
	const double	theta = get_polar_angle(orientation, axis);
	t_matrix		*matrix;

	matrix = init_matrix(4, 4);
	matrix->data[0] = cos(phi);
	matrix->data[1] = sin(phi) * sin(theta);
	matrix->data[2] = sin(phi) * cos(theta);
	matrix->data[3] = translation.x;
	matrix->data[4] = 0;
	matrix->data[5] = cos(theta);
	matrix->data[6] = -1 * sin(theta);
	matrix->data[7] = translation.y;
	matrix->data[8] = -1 * sin(phi);
	matrix->data[9] = cos(phi) * sin(theta);
	matrix->data[10] = cos(phi) * cos(theta);
	matrix->data[11] = translation.z;
	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1;
	return (matrix);
}

static double	get_polar_angle(t_vec orientation, char axis)
{
	double	theta;

	theta = acos(orientation.y);
	if (axis == 'Z' || axis == 'X')
		theta -= PI / 2;
	return (theta);
}

t_matrix	*construct_basic_matrix_inverse(t_point translation, \
			t_vec orientation, char axis)
{
	const double	phi = atan2(orientation.x, orientation.z);
	const double	theta = get_polar_angle(orientation, axis);
	t_matrix		*matrix;

	matrix = init_matrix(4, 4);
	matrix->data[0] = cos(phi);
	matrix->data[1] = 0;
	matrix->data[2] = -1 * sin(phi);
	matrix->data[3] = translation.z * sin(phi) - translation.x * cos(phi);
	matrix->data[4] = sin(theta) * sin(phi);
	matrix->data[5] = cos(theta);
	matrix->data[6] = sin(theta) * cos(phi);
	matrix->data[7] = translation.y * cos(theta) * -1 - sin(theta) * \
	(translation.x * sin(phi) + translation.z * cos(phi));
	matrix->data[8] = cos(theta) * sin(phi);
	matrix->data[9] = -1 * sin(theta);
	matrix->data[10] = cos(phi) * cos(theta);
	matrix->data[11] = -1 * translation.x * cos(theta) * sin(phi) + \
	translation.y * sin(theta) - translation.z * cos(theta) * cos(phi);
	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1;
	return (matrix);
}

t_vec	multiply_matrix_by_directional_vector(t_matrix matrix, t_vec *vec)
{
	t_matrix	*temp_matrix;
	t_vec		result;

	temp_matrix = deep_copy_matrix(&matrix);
	temp_matrix->data[3] = 0;
	temp_matrix->data[7] = 0;
	temp_matrix->data[11] = 0;
	temp_matrix->data[15] = 0;
	result = multiply_matrix_by_4d_vec(temp_matrix, vec);
	free(temp_matrix->data);
	free(temp_matrix);
	return (result);
}
