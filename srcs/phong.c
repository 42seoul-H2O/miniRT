/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:10:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/20 12:29:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	vec_truncate(t_vec vector, t_scalar threshold);

t_color	phong_lighting(t_info *info, t_hit_record *rec)
{
	t_vec	light;

	light = get_point_light(info, rec);
	light = vec_sum(light, info->light.ambient);
	light = new_vector(light.x * rec->albedo.x, light.y * rec->albedo.y, \
						light.z * rec->albedo.z);
	light = vec_truncate(light, 1.0);
	return (vec_to_color(light));
}

t_vec	get_point_light(t_info *info, t_hit_record *rec)
{
	t_vec	result;
	t_vec	light_dir;
	double	diffuse_strength;

	light_dir = vec_normalize(vec_sub(info->light.light_coor, rec->p));
	diffuse_strength = fmax(vec_dot(rec->normal, light_dir), 0.0);
	result = vec_mul(new_vector(1, 1, 1), diffuse_strength);
	return (result);
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
