/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 17:22:03 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/19 13:52:51 by hocsong          ###   ########seoul.kr  */
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

t_matrix	*deep_copy_matrix(t_matrix *orig)
{
	t_matrix	*new_matrix;
	int			i;

	new_matrix = init_matrix(orig->row_dimension, orig->column_dimension);
	i = 0;
	while (i < 16)
	{
		new_matrix->data[i] = orig->data[i];
		i++;
	}
	return (new_matrix);
}