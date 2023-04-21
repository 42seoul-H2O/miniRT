/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:56:22 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/21 10:46:34 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_intersection function returns a value of a parameter t of a ray 
	where the ray would intersect.
*/

#include "minirt.h"

static double	get_intersection_sphere(t_sphere sphere, t_ray ray);
static t_point	get_texture_coord_sphere(t_point point);
static t_vec	get_normal_sphere(t_sphere sphere, t_point point);

t_color	get_color_sphere(t_sphere sphere, int pixel_x, int pixel_y)
{
	t_color	color;

	color = new_color(0, 255, 0);
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
	determinant = pow(b, 2) - 4 * c < 0;
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

static t_point	get_texture_coord_sphere(t_point point)
{
	t_spherical_coord	spherical_coord;
	t_point				texture_coord;

	spherical_coord = get_spherical_coord(point);
	texture_coord = new_vector(spherical_coord.phi / (2 * PI), \
	spherical_coord.theta / (PI), 0, 1);
	return (texture_coord);
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

	spherical_coord.phi = atan(point.x / point.z);
	spherical_coord.theta = atan(point.x / point.y);
	return (spherical_coord);
}
