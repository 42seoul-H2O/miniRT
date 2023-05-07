/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:16 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/07 18:02:03 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_world_to_cylinder_cooridnate does not return cylindrical coordinate.
	It returns a local coordinate where the local y axis is the axis of the cylinder.
*/

#include "minirt.h"

static t_point	get_local_intersection_cylinder(t_cylinder cylinder, \
				t_ray ray, int *err_flag);
static t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point);

t_color	get_color_cylinder(t_info *info, t_cylinder cylinder, t_ray ray)
{
	double	t;
	t_color	color;
	t_point	point_on_cylinder;
	double	cos_theta;

	t = get_intersection_cylinder(cylinder, ray);
	point_on_cylinder = ray_to_point(ray, t);
	cos_theta = vec_dot(\
	vec_normalize(vec_sub(info->light.light_coor, point_on_cylinder)), get_normal_cylinder(cylinder, point_on_cylinder));
	if (cos_theta < 0)
		cos_theta = 0;
	color.red = floor(get_diffuse_radiance(info, cylinder.color.red, point_on_cylinder, cos_theta));
	color.green = floor(get_diffuse_radiance(info, cylinder.color.green, point_on_cylinder, cos_theta));
	color.blue = floor(get_diffuse_radiance(info, cylinder.color.blue, point_on_cylinder, cos_theta));
	return (color);
}

double	get_intersection_cylinder(t_cylinder cylinder, t_ray ray)
{
	int			has_found[2];
	t_ray		local_ray;
	t_point		local_intersection_point;
	t_point		global_intersection_point;

	local_ray.orig = multiply_matrix_by_4d_vec(\
	cylinder.world_to_cylinder, &(ray.orig));
	local_ray.dir = multiply_matrix_by_4d_vec(\
	cylinder.world_to_cylinder, &(ray.dir));
	local_intersection_point = get_local_intersection_cylinder(\
	cylinder, local_ray, has_found, has_found + 1);
	if (!has_found[0] && !has_found[1])
		return (-1);
	global_intersection_point = multiply_matrix_by_4d_vec(\
	cylinder.cylinder_to_world, &local_intersection_point);
	return (point_to_ray_parameter(ray, global_intersection_point));
}

static t_point	get_local_intersection_cylinder(t_cylinder cylinder, t_ray ray,\
				int *has_found_lateral, int *has_found_base)
{
	t_point	local_intersection_lateral;
	t_point	local_intersection_base;
	double	t_lateral;
	double	t_base;

	*has_found_lateral = 1;
	*has_found_base = 1;
	local_intersection_lateral = get_local_intersection_lateral(\
	cylinder, ray, has_found_lateral);
	local_intersection_base = get_local_intersection_base(\
	cylinder, ray, has_found_base);
	if (*has_found_lateral && !*has_found_base)
		return (local_intersection_lateral);
	else if (!*has_found_lateral && *has_found_base)
		return (local_intersection_base);
	else if (*has_found_lateral && *has_found_base)
	{
		t_lateral = point_to_ray_parameter(ray, local_intersection_lateral);
		t_base = point_to_ray_parameter(ray, local_intersection_base);
		if (t_lateral <= t_base)
			return (local_intersection_lateral);
		return (local_intersection_base);
	}
	else
		return (local_intersection_lateral);
}

static t_point	get_local_intersection_lateral(t_cylinder cylinder, \
				t_ray ray, int *has_found)
{
	const double	b = ray.orig.x * ray.dir.x + ray.orig.z * ray.dir.z;
	const double	c = pow(ray.orig.x, 2) + pow(ray.orig.z, 2) \
	- pow(cylinder.diameter / 2, 2);
	double			t;
	t_point			local_intersection_point;

	local_intersection_point = new_vector(0, 0, 0, 1);
	if (pow(b, 2) - 4 * c >= 0)
	{
		t = (-1 * b - sqrt(pow(b, 2) - 4 * c)) / 2;
		local_intersection_point = ray_to_point(ray, t);
		if (t >= 0 && fabs(local_intersection_point.y) <= (cylinder.height / 2))
			return (local_intersection_point);
		t = (-1 * b + sqrt(pow(b, 2) - 4 * c)) / 2;
		local_intersection_point = ray_to_point(ray, t);
		if (t >= 0 && fabs(local_intersection_point.y) <= (cylinder.height / 2))
			return (local_intersection_point);
	}
	*has_found = 0;
	return (local_intersection_point);
}

static t_point	get_local_intersection_base(t_cylinder cylinder, \
				t_ray ray, int *err_flag)
{
	
}

static t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point)
{
	t_vec	normal_vector;

	normal_vector = vec_sub(point, cylinder.center);
	normal_vector = vec_normalize(normal_vector);
	return (normal_vector);
}
