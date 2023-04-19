/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 19:56:22 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/19 20:15:01 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	returns a value of a parameter t of a ray where the ray would intersect.
*/

#include "minirt.h"

double	get_ray_sphere_intersection(t_sphere sphere, t_ray ray)
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
