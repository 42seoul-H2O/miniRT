/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:16 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/05 20:42:27 by hocsong          ###   ########seoul.kr  */
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
	double		t;
	t_matrix	*matrix;

	matrix = construct_basic_matrix(cylinder.center, vec_normalize(cylinder.axis)); // y의 값이 cylinder height 범위 내에 있는지도 체크해야된다.
	
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
