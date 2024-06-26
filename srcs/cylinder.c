/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:12:16 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/25 15:38:30 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_world_to_cylinder_cooridnate does not return cylindrical coordinate.
	It returns a local coordinate where the local y axis is the axis of the 
	cylinder.
*/

#include "minirt.h"

static int		get_point_type(t_cylinder cylinder, t_point point);

t_color	get_color_cylinder(t_info *info, t_cylinder cylinder, t_ray ray)
{
	double	t;
	t_color	color;
	t_point	point_on_cylinder;
	double	cos_theta;

	t = get_intersection_cylinder(cylinder, ray);
	point_on_cylinder = ray_to_point(ray, t);
	cos_theta = vec_dot(\
	vec_normalize(vec_sub(info->light.light_coor, point_on_cylinder)), \
	get_normal_cylinder(cylinder, point_on_cylinder));
	if (cos_theta < 0)
		cos_theta = 0;
	color.red = floor(get_radiance(info, cylinder.color.red, RED, cos_theta));
	color.green = floor(get_radiance(\
	info, cylinder.color.green, GREEN, cos_theta));
	color.blue = floor(get_radiance(\
	info, cylinder.color.blue, BLUE, cos_theta));
	return (color);
}

t_vec	get_normal_cylinder(t_cylinder cylinder, t_point point)
{
	int		point_type;
	t_vec	normal_vector_cylindrical;
	t_vec	global_normal_vector;
	double	phi;

	point = multiply_matrix_by_4d_vec(cylinder.world_to_cylinder, &point);
	phi = atan2(point.x, point.z);
	point_type = get_point_type(cylinder, point);
	if (point_type != LATERAL)
	{
		if (point_type == TOP_BASE)
			normal_vector_cylindrical = new_vector(0, 1, 0, 1);
		else
			normal_vector_cylindrical = new_vector(0, -1, 0, 1);
		global_normal_vector = multiply_matrix_by_directional_vector(\
		*cylinder.cylinder_to_world, &normal_vector_cylindrical);
		global_normal_vector = vec_normalize(global_normal_vector);
		return (global_normal_vector);
	}
	normal_vector_cylindrical = new_vector(sin(phi), 0, cos(phi), 1);
	global_normal_vector = multiply_matrix_by_directional_vector(\
	*cylinder.cylinder_to_world, &normal_vector_cylindrical);
	global_normal_vector = vec_normalize(global_normal_vector);
	return (global_normal_vector);
}

static int	get_point_type(t_cylinder cylinder, t_point point)
{
	if (fabs(fabs(point.y) - cylinder.height / 2) > .0000001)
		return (LATERAL);
	else if (point.y >= 0)
		return (TOP_BASE);
	else
		return (BOTTOM_BASE);
}
