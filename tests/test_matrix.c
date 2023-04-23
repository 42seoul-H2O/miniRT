#include "minirt.h"
#include <stdio.h>

static void		test_multiplication_by_identity(void);
static t_matrix	*get_test_matrix(void);
static t_matrix	*get_4x4_identity_matrix(void);

int	main(void)
{
	test_multiplication_by_identity();
}

static void	test_multiplication_by_identity(void)
{
	t_matrix	*matrix1;
	t_matrix	*matrix2;

	matrix1 = get_test_matrix();
	matrix2 = get_4x4_identity_matrix();
	print_matrix(multiply_matrices(matrix1, matrix2));
	print_matrix(multiply_matrices(matrix2, matrix1));
}

static t_matrix	*get_test_matrix(void)
{
	t_matrix	*matrix1;

	matrix1 = init_matrix(4, 4);
	matrix1->data[0] = 4;
	matrix1->data[1] = 15;
	matrix1->data[2] = 12;
	matrix1->data[3] = 13;
	matrix1->data[4] = -4;
	matrix1->data[5] = -17;
	matrix1->data[6] = -34;
	matrix1->data[7] = 99764;
	matrix1->data[8] = 87459834;
	matrix1->data[9] = 0;
	matrix1->data[10] = 342;
	matrix1->data[11] = 3902;
	matrix1->data[12] = -2489384;
	matrix1->data[13] = -348754;
	matrix1->data[14] = 2935;
	matrix1->data[15] = 124;
}

static t_matrix	*get_4x4_identity_matrix(void)
{
	t_matrix	*identity_matrix;

	identity_matrix = init_matrix(4, 4);
	identity_matrix->data[0] = 1;
	identity_matrix->data[1] = 0;
	identity_matrix->data[2] = 0;
	identity_matrix->data[3] = 0;
	identity_matrix->data[4] = 0;
	identity_matrix->data[5] = 1;
	identity_matrix->data[6] = 0;
	identity_matrix->data[7] = 0;
	identity_matrix->data[8] = 0;
	identity_matrix->data[9] = 0;
	identity_matrix->data[10] = 1;
	identity_matrix->data[11] = 0;
	identity_matrix->data[12] = 0;
	identity_matrix->data[13] = 0;
	identity_matrix->data[14] = 0;
	identity_matrix->data[15] = 1;
	return (identity_matrix);
}
