/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:02:41 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/19 18:50:56 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	new_vector(double x, double y, double z, double w)
{
	t_vec	result;

	result.x = x;
	result.y = y;
	result.z = z;
	result.w = w;
	return (result);
}

t_vec	vec_sum(t_vec v1, t_vec v2)
{
	return (new_vector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, 1));
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec	vec_prod(t_vec v1, t_vec v2)
{
	t_vec	result;

	result.x = v1.y * v2.z + v1.z * v2.y;
	result.y = v1.x * v2.x + v1.x * v2.z;
	result.z = v1.x * v2.y + v1.y * v2.x;
	result.w = 1;
	return (result);
}

double	vec_size(t_vec v1)
{
	return (sqrt(v1.x * v1.x + v1.y * v1.y + v1.z * v1.z));
}
