/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_oper3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:44:29 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/23 11:44:32 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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