/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_oper2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 19:15:55 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/20 11:48:03 by hyunjuki         ###   ########.fr       */
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

t_color	vec_to_color(t_vec normalized)
{
	if (normalized.x > 1 || normalized.y > 1 || normalized.z > 1)
		puterr_and_exit("Color Vector exceeded.", "");
	normalized = vec_mul(normalized, 255.0);
	return (new_color(normalized.x, normalized.y, normalized.z));
}

t_vec	color_to_vec(t_color color)
{
	t_vec	result;

	result.x = color.red / 255.0;
	result.y = color.green / 255.0;
	result.z = color.blue / 255.0;
	return (result);
}
