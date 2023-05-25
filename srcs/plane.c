/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:39:19 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/25 15:37:33 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	get_color_plane(t_info *info, t_plane plane, t_ray ray)
{
	t_color	color;
	double	t;
	t_point	point_on_plane;
	double	cos_theta;

	t = get_intersection_plane(plane, ray);
	point_on_plane = ray_to_point(ray, t);
	cos_theta = vec_dot(\
	vec_normalize(vec_sub(info->light.light_coor, point_on_plane)), \
	get_normal_plane(info, plane));
	if (cos_theta < 0)
		cos_theta = 0;
	color.red = floor(get_radiance(info, plane.color.red, RED, cos_theta));
	color.green = floor(get_radiance(\
	info, plane.color.green, GREEN, cos_theta));
	color.blue = floor(get_radiance(info, plane.color.blue, BLUE, cos_theta));
	return (color);
}

double	get_intersection_plane(t_plane plane, t_ray ray)
{
	double	t;
	double	nominator;
	double	denominator;

	nominator = vec_dot(vec_sub(plane.center, ray.orig), plane.normal);
	denominator = vec_dot(ray.dir, plane.normal);
	if (fabs(denominator) <= 0.000000001)
		return (-1);
	t = nominator / denominator;
	return (t);
}

t_vec	get_normal_plane(t_info *info, t_plane plane)
{
	t_vec	plane_normal;
	t_vec	plane_to_camera_vec;

	plane_to_camera_vec = vec_sub(info->camera.viewpoint, plane.center);
	plane_to_camera_vec = vec_normalize(plane_to_camera_vec);
	if (vec_dot(plane.normal, plane_to_camera_vec) < 0)
		plane_normal = vec_mul(plane.normal, -1);
	else
		plane_normal = plane.normal;
	return (plane_normal);
}
