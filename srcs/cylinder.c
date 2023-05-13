/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:16 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/13 21:20:38 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_world_to_cylinder_cooridnate does not return cylindrical coordinate.
	It returns a local coordinate where the local y axis is the axis of the 
	cylinder.
*/

#include "minirt.h"

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

static t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point) // base에 normal인 경우를 따로 고려해줘야 한다.
{
	t_vec			local_normal_vector;
	t_vec			global_normal_vector;
	const double	phi = atan2(point.x, point.z);

	local_normal_vector = new_vector(cos(phi), 0, sin(phi), 1);
	global_normal_vector = multiply_matrix_by_4d_vec(\
	cylinder.cylinder_to_world, &local_normal_vector);
	global_normal_vector = vec_sub(global_normal_vector, cylinder.center);
	return (global_normal_vector);
}
