/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:10:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/26 17:11:34 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	vec_truncate(t_vec vector, t_scalar threshold);

t_color	phong_lighting(t_info *info, t_ray ray, t_hit_record *rec)
{
	t_vec	light;

	light = get_point_light(info, ray, rec);
	light = vec_sum(light, info->light.ambient);
	light = new_vector(light.x * rec->albedo.x, light.y * rec->albedo.y, \
						light.z * rec->albedo.z);
	light = vec_truncate(light, 1.0);
	return (vec_to_color(light));
}

t_vec	get_point_light(t_info *info, t_ray ray, t_hit_record *rec)
{
	t_vec	result;
	t_vec	light_dir;
	t_ray	light_ray;
	double	diffuse_strength;
	double	brightness;

	light_dir = vec_sub(info->light.light_coor, rec->p);
	light_ray = new_ray(vec_sum(rec->p, vec_mul(rec->normal, 0.000001)), \
		light_dir);
	if (in_shadow(info, light_ray, vec_size(light_dir)))
		return (new_vector(0, 0, 0));
	light_dir = vec_normalize(light_dir);
	diffuse_strength = fmax(vec_dot(rec->normal, light_dir), 0.0);
	result = vec_mul(new_vector(1, 1, 1), diffuse_strength);
	result = vec_sum(result, get_specular_light(ray, light_dir, rec));
	brightness = info->light.brightness * LUMEN;
	result = vec_mul(result, brightness);
	return (result);
}

t_vec	get_specular_light(t_ray ray, t_vec light_dir, t_hit_record *rec)
{
	t_vec	view_dir;
	t_vec	reflect_dir;
	double	spec;

	view_dir = vec_normalize(vec_mul(ray.dir, -1));
	reflect_dir = vec_mul(light_dir, -1);
	reflect_dir = vec_mul(rec->normal, vec_dot(rec->normal, reflect_dir) * 2);
	reflect_dir = vec_sub(vec_mul(light_dir, -1), reflect_dir);
	spec = pow(fmax(vec_dot(view_dir, reflect_dir), 0.0), SPECULAR_BRIGHTNESS);
	return (vec_mul(vec_mul(new_vector(1, 1, 1), SPECULAR_STRENGTH), spec));
}

int	in_shadow(t_info *info, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (check_ray_hit(light_ray, info, &rec) != -1)
		return (1);
	return (0);
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
