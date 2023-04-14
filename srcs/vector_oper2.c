/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:15:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/14 11:18:57 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_mul(t_vec vector, t_scalar scalar)
{
	return (new_vector(vector.x * scalar, \
		vector.y * scalar, vector.z * scalar));
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return (new_vector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z));
}

t_vec	vec_normalize(t_vec vector)
{
	double	size;

	size = vec_size(vector);
	if (size == 0)
		puterr_and_exit("Devider Vector's size is 0.", "");
	return (new_vector(vector.x / size, vector.y / size, vector.z / size));
}
