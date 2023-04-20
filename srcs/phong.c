/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:10:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/20 11:51:48 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	vec_truncate(t_vec vector, t_scalar threshold);

t_color	phong_lighting(t_info *info, t_hit_record *rec)
{
	t_vec	light;

	light = new_vector(0, 0, 0);
	light = vec_sum(light, info->light.ambient);
	light = new_vector(light.x * rec->albedo.x, light.y * rec->albedo.y, \
						light.z * rec->albedo.z);
	light = vec_truncate(light, 1.0);
	return (vec_to_color(light));
}

static t_vec	vec_truncate(t_vec vector, t_scalar threshold)
{
	if (vector.x > threshold)
		vector.x = threshold;
	if (vector.y > threshold)
		vector.y = threshold;
	if (vector.z > threshold)
		vector.z = threshold;
	return (vector);
}
