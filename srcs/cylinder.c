/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:16 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/05 16:12:41 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point);

t_color	get_color_cylinder(t_info *info, t_cylinder cylinder, t_ray ray)
{
	t_color	color;
	double	t;
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
	double	t;
	double	b;
	double	c;
	double	determinant;

	b = vec_dot(vec_mul(ray.dir, 2), vec_sub(ray.orig, cylinder.center));
	c = pow(vec_size(vec_sub(ray.orig, cylinder.center)), 2);
	c -= pow((cylinder.diameter / 2.0), 2);
	determinant = pow(b, 2) - 4 * c;
	if (determinant < 0)
		return (-1);
	t = (-1 * b - sqrt(determinant)) / 2.0;
	if (t >= 0)
		return (t);
	else
	{
		t = (-1 * b + sqrt(determinant)) / 2.0;
		return (t);
	}
}

static t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point)
{
	t_vec	normal_vector;

	normal_vector = vec_sub(point, cylinder.center);
	normal_vector = vec_normalize(normal_vector);
	return (normal_vector);
}

// t_spherical_coord	get_spherical_coord(t_point point)
// {
// 	t_spherical_coord	spherical_coord;

// 	spherical_coord.phi = atan2(point.x, point.z);
// 	spherical_coord.theta = acos(point.y / vec_size(point));
// 	return (spherical_coord);
// }
