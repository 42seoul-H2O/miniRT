/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:15:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/03 17:08:01 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_mul(t_vec vector, t_scalar scalar)
{
	return (new_vector(vector.x * scalar, \
		vector.y * scalar, vector.z * scalar, 1));
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 1));
}

t_vec	vec_normalize(t_vec vector)
{
	double	size;

	size = vec_size(vector);
	if (size == 0)
		puterr_and_exit("Devider Vector's size is 0.", "");
	return (new_vector(vector.x / size, vector.y / size, vector.z / size, 1));
}

double	get_vec_distance(t_vec v1, t_vec v2)
{
	t_vec	temp_v;

	temp_v = vec_sub(v1, v2);
	return (vec_size(temp_v));
}
