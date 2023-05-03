/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:56:22 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/03 12:00:35 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_intersection function returns a value of a parameter t of a ray 
	where the ray would intersect.
*/

#include "minirt.h"

static t_vec	get_normal_sphere(t_sphere sphere, t_point point);

t_color	get_color_sphere(t_sphere sphere, t_ray ray)
{
	t_color	color;
	double	facing_ratio;
	double	t;

	t = get_intersection_sphere(sphere, ray);
	facing_ratio = vec_dot(vec_mul(ray.dir, -1), get_normal_sphere(sphere, ray_to_point(ray, t)));
	color.red = sphere.color.red * facing_ratio;
	color.green = sphere.color.green * facing_ratio;
	color.blue = sphere.color.blue * facing_ratio;
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

static t_vec	get_normal_sphere(t_sphere sphere, t_point point)
{
	t_vec	normal_vector;

	normal_vector = vec_sub(point, sphere.center);
	normal_vector = vec_normalize(normal_vector);
	return (normal_vector);
}

t_spherical_coord	get_spherical_coord(t_point point)
{
	t_spherical_coord	spherical_coord;

	spherical_coord.phi = atan2(point.x, point.z);
	spherical_coord.theta = acos(point.y / vec_size(point));
	return (spherical_coord);
}
