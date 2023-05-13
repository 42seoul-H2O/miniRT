/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 18:20:06 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/13 18:08:09 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
	get_local_intersection_base need not consider a case where a determinant is 0
	since a determinant of 0 implies that there is only one solution for t that
	is within the distance of radius from the axis of a cylinder.
	It also implies that the intersection point lies both on a lateral side and 
	a base. Thus, we only need get_local_intersection_lateral function to deal with
	such a case.
*/

static t_point	get_local_intersection_cylinder(t_cylinder cylinder, t_ray ray,\
				int *has_found_lateral, int *has_found_base);
static t_point	get_local_intersection_lateral(t_cylinder cylinder, \
				t_ray ray, int *has_found);
static t_point	get_local_intersection_base(t_cylinder cylinder, \
				t_ray ray, int *has_found);
static int		is_valid_intersection(double t, \
				t_point intersection_point, double radius);

double	get_intersection_cylinder(t_cylinder cylinder, t_ray ray)
{
	int			has_found[2];
	t_ray		local_ray;
	t_point		local_intersection_point;
	t_point		global_intersection_point;

	local_ray = apply_matrix_to_ray(ray, cylinder.world_to_cylinder);
	local_intersection_point = get_local_intersection_cylinder(\
	cylinder, local_ray, has_found, has_found + 1);
	if (!has_found[0] && !has_found[1])
		return (-1);
	global_intersection_point = multiply_matrix_by_4d_vec(\
	cylinder.cylinder_to_world, &local_intersection_point);
	return (point_to_ray_parameter(ray, global_intersection_point));
}

static t_point	get_local_intersection_cylinder(t_cylinder cylinder, t_ray ray,\
				int *has_found_lateral, int *has_found_base)
{
	t_point	local_intersection_lateral;
	t_point	local_intersection_base;
	double	t_lateral;
	double	t_base;

	*has_found_lateral = 1;
	*has_found_base = 1;
	local_intersection_lateral = get_local_intersection_lateral(\
	cylinder, ray, has_found_lateral);
	local_intersection_base = get_local_intersection_base(\
	cylinder, ray, has_found_base);
	if (*has_found_lateral && !*has_found_base)
		return (local_intersection_lateral);
	else if (!*has_found_lateral && *has_found_base)
		return (local_intersection_base);
	else if (*has_found_lateral && *has_found_base)
	{
		t_lateral = point_to_ray_parameter(ray, local_intersection_lateral);
		t_base = point_to_ray_parameter(ray, local_intersection_base);
		if (t_lateral <= t_base)
			return (local_intersection_lateral);
		return (local_intersection_base);
	}
	else
		return (local_intersection_lateral);
}

static t_point	get_local_intersection_lateral(t_cylinder cylinder, \
				t_ray ray, int *has_found)
{
	const double	a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	const double	b = 2 * (ray.orig.x * ray.dir.x + ray.orig.z * ray.dir.z);
	const double	c = pow(ray.orig.x, 2) + pow(ray.orig.z, 2) \
	- pow(cylinder.diameter / 2, 2);
	double			t;
	t_point			local_intersection_point;

	local_intersection_point = new_vector(0, 0, 0, 1);
	if (pow(b, 2) - 4 * a * c >= 0)
	{
		t = (-1 * b - sqrt(pow(b, 2) - 4 * a * c)) / \
		(2 * a);
		local_intersection_point = ray_to_point(ray, t);
		if (t >= 0 && fabs(local_intersection_point.y) <= (cylinder.height / 2))
			return (local_intersection_point);
		t = (-1 * b + sqrt(pow(b, 2) - 4 * a * c)) / \
		(2 * a);
		local_intersection_point = ray_to_point(ray, t);
		if (t >= 0 && fabs(local_intersection_point.y) <= (cylinder.height / 2))
			return (local_intersection_point);
	}
	*has_found = 0;
	return (local_intersection_point);
}

static t_point	get_local_intersection_base(t_cylinder cylinder, \
				t_ray ray, int *has_found)
{
	double	t1;
	double	t2;
	t_point	p1;
	t_point	p2;

	t1 = point_to_ray_parameter(ray, new_vector(\
		0, cylinder.height / 2 * -1, 0, 1));
	t2 = point_to_ray_parameter(ray, new_vector(\
		0, cylinder.height / 2, 0, 1));
	p1 = ray_to_point(ray, t1);
	p2 = ray_to_point(ray, t2);
	if (!is_valid_intersection(t1, p1, cylinder.diameter / 2) && \
	!is_valid_intersection(t2, p2, cylinder.diameter / 2))
		*has_found = 0;
	else if (is_valid_intersection(t1, p1, cylinder.diameter / 2) && \
	!is_valid_intersection(t2, p2, cylinder.diameter / 2))
		return (p1);
	else if (!is_valid_intersection(t1, p1, cylinder.diameter / 2) && \
	is_valid_intersection(t2, p2, cylinder.diameter / 2))
		return (p2);
	return (new_vector(0, 0, 0, 1));
}

static int	is_valid_intersection(double t, \
			t_point intersection_point, double radius)
{
	if (t > 0 && radius >= pow(intersection_point.x, 2) \
	+ pow(intersection_point.z, 2))
		return (1);
	return (0);
}
