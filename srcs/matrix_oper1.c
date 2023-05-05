/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:22:03 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/05 19:01:21 by hocsong          ###   ########seoul.kr  */
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
}

t_matrix	*construct_basic_matrix(t_point translation, t_vec orientation)
{
	const double	phi = atan2(-1 * orientation.x, -1 * orientation.z);
	const double	theta = acos(orientation.y) - PI / 2;
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
