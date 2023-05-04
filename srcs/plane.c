/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:39:19 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/04 16:59:59 by hocsong          ###   ########seoul.kr  */
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
	plane.normal);
	if (cos_theta < 0)
		cos_theta = 0;
	color.red = floor(get_diffuse_radiance(\
	info, plane.color.red, point_on_plane, cos_theta));
	color.green = floor(get_diffuse_radiance(\
	info, plane.color.green, point_on_plane, cos_theta));
	color.blue = floor(get_diffuse_radiance(\
	info, plane.color.blue, point_on_plane, cos_theta));
	return (color);
}

double	get_intersection_plane(t_plane plane, t_ray ray)
{
	double	t;
	double	nominator;
	double	denominator;

	nominator = vec_dot(vec_sub(plane.center, ray.orig), plane.normal);
	denominator = vec_dot(ray.dir, plane.normal);
	if (abs(denominator) <= 0.0001)
		return (-1);
	t = nominator / denominator;
	return (t);
}
