/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:22:03 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/16 20:09:44 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	*init_matrix(int row_dimension, int column_dimension)
{
	t_matrix	*matrix;

	matrix = malloc(sizeof (t_matrix));
	if (!matrix)
		puterr_and_exit("Failed to allocate memory : ", "t_matrix");
	matrix->row_dimension = row_dimension;
	matrix->column_dimension = column_dimension;
	matrix->data = malloc(sizeof (double) * (row_dimension * column_dimension));
	if (!matrix->data)
		puterr_and_exit("Failed to allocate memory : ", "data of t_matrix");
	return (matrix);
}

void	destroy_matrix(t_matrix *matrix)
{
	free(matrix->data);
	free(matrix);
}

double	get_matrix_item(t_matrix *matrix, int row_index, int column_index)
{
	int	data_index;

	data_index = row_index * matrix->column_dimension + column_index;
	return (matrix->data[data_index]);
}

void	set_matrix_item(t_matrix *matrix, int row_index, int column_index, \
	double entry)
{
	int	data_index;

	data_index = row_index * matrix->column_dimension + column_index;
	matrix->data[data_index] = entry;
	return (1);
}

t_matrix	*construct_basic_matrix(t_point translation, t_point rotation, \
			t_point scale)
{
	t_matrix	*basic_matrix;

	basic_matrix = init_matrix_size(4, 4);
	basic_matrix->data[0] = scale.x * cos(rotation.y) * cos(rotation.z);
	basic_matrix->data[1] = sin(rotation.x) * sin(rotation.y) * \
	cos(rotation.z) - cos(rotation.x) * sin(rotation.z);
	basic_matrix->data[2] = cos(rotation.x) * sin(rotation.y) * \
	cos(rotation.z) + sin(rotation.x) * sin(rotation.z);
	basic_matrix->data[3] = translation.x;
	basic_matrix->data[4] = cos(rotation.y) * sin(rotation.z);
	basic_matrix->data[5] = scale.y * sin(rotation.x) * sin(rotation.y) * \
	sin(rotation.z) + cos(rotation.x) * cos(rotation.z);
	basic_matrix->data[6] = cos(rotation.x) * sin(rotation.y) * \
	sin(rotation.z) - sin(rotation.x) * cos(rotation.z);
	basic_matrix->data[7] = translation.y;
	basic_matrix->data[8] = -sin(rotation.y);
	basic_matrix->data[9] = sin(rotation.x) * cos(rotation.y);
	basic_matrix->data[10] = scale.z * cos(rotation.x) * cos(rotation.y);
	basic_matrix->data[11] = translation.z;
	basic_matrix->data[12] = 0;
	basic_matrix->data[13] = 0;
	basic_matrix->data[14] = 0;
	basic_matrix->data[15] = 1;
	return (basic_matrix);
}
