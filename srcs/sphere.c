/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:56:22 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/25 15:35:50 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_intersection function returns a value of a parameter t of a ray 
	where the ray would intersect.
*/

/*
	get_color_sphere's theta is the angle between the normal vector of the surface
	at the point and the ray from the sphere's surface to the light source
*/

#include "minirt.h"

t_color	get_color_sphere(t_info *info, t_sphere sphere, t_ray ray)
{
	t_color	color;
	double	t;
	t_point	point_on_sphere;
	double	cos_theta;

	t = get_intersection_sphere(sphere, ray);
	point_on_sphere = ray_to_point(ray, t);
	cos_theta = vec_dot(\
	vec_normalize(vec_sub(info->light.light_coor, point_on_sphere)), \
	get_normal_sphere(sphere, point_on_sphere));
	if (cos_theta < 0)
		cos_theta = 0;
	color.red = floor(get_radiance(info, sphere.color.red, RED, cos_theta));
	color.green = floor(get_radiance(\
	info, sphere.color.green, GREEN, cos_theta));
	color.blue = floor(get_radiance(info, sphere.color.blue, BLUE, cos_theta));
	return (color);
}

double	get_intersection_sphere(t_sphere sphere, t_ray ray)
{
	double	t;
	double	b;
	double	c;
	double	determinant;

	b = vec_dot(vec_mul(ray.dir, 2), vec_sub(ray.orig, sphere.center));
	c = pow(vec_size(vec_sub(ray.orig, sphere.center)), 2);
	c -= pow((sphere.diameter / 2.0), 2);
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

t_vec	get_normal_sphere(t_sphere sphere, t_point point)
{
	t_vec	normal_vector;

	normal_vector = vec_sub(point, sphere.center);
	normal_vector = vec_normalize(normal_vector);
	return (normal_vector);
}
