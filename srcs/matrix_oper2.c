/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:45:17 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/16 20:17:22 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	multiply_row_by_column(t_matrix *matrix1, t_matrix *matrix2, \
				int matrix1_row_idx, int matrix2_col_idx);
static t_matrix	*four_dimensional_vec_to_matrix(t_vec *vec);
static t_vec	matrix_to_4dvec(t_matrix *matrix);

t_matrix	*multiply_matrices(t_matrix *matrix1, t_matrix *matrix2)
{
	t_matrix	*resultant_matrix;
	int			matrix1_row_idx;
	int			matrix2_col_idx;
	double		item;

	if (matrix1->column_dimension != matrix2->row_dimension)
		puterr_and_exit("Matrix multiplication with wrong dimensions.", \
		"matrix * vec");
	matrix1_row_idx = 0;
	matrix2_col_idx = 0;
	resultant_matrix = init_matrix(matrix1->column_dimension, \
	matrix2->row_dimension);
	while (matrix1_row_idx < matrix1->row_dimension)
	{
		while (matrix2_col_idx < matrix2->column_dimension)
		{
			item = multiply_row_by_column(matrix1, matrix2, matrix1_row_idx, \
			matrix2_col_idx);
			set_matrix_item(resultant_matrix, matrix1_row_idx, \
			matrix2_col_idx, item);
			matrix2_col_idx++;
		}
		matrix1_row_idx++;
	}
	return (resultant_matrix);
}

t_vec	multiply_matrix_by_4d_vec(t_matrix *matrix, t_vec *vec)
{
	t_vec		resultant_vector;
	t_matrix	*temp_matrix;
	t_matrix	*resultant_matrix;

	resultant_vector = new_vector(0, 0, 0, 0);
	temp_matrix = vec_to_matrix(vec);
	resultant_matrix = multiply_matrices(matrix, temp_matrix);
	resultant_vector = matrix_to_4dvec(resultant_matrix);
	destroy_matrix(temp_matrix);
	destroy_matrix(resultant_matrix);
	return (resultant_vector);
}

static double	multiply_row_by_column(t_matrix *matrix1, t_matrix *matrix2, \
		int matrix1_row_idx, int matrix2_col_idx)
{
	int		matrix1_col_idx;
	int		matrix2_row_idx;
	double	result;

	matrix1_col_idx = 0;
	matrix2_row_idx = 0;
	result = 0;
	while (matrix1_col_idx < matrix1->column_dimension)
	{
		result += get_matrix_item(matrix1, matrix1_row_idx, matrix1_col_idx) * \
		get_matrix_item(matrix2, matrix2_row_idx, matrix2_col_idx);
		matrix1_col_idx++;
		matrix2_row_idx++;
	}
	return (result);
}

static t_matrix	*four_dimensional_vec_to_matrix(t_vec *vec)
{
	t_matrix	*matrix;

	matrix = init_matrix(4, 1);
	matrix->data[0] = vec->x;
	matrix->data[1] = vec->y;
	matrix->data[2] = vec->z;
	matrix->data[3] = vec->w;
	return (matrix);
}

static t_vec	matrix_to_4dvec(t_matrix *matrix)
{
	t_vec	vector;

	vector.x = matrix->data[0];
	vector.y = matrix->data[1];
	vector.z = matrix->data[2];
	vector.w = matrix->data[3];
	return (vector);
}