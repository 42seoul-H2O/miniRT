/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:58 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/10 22:09:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_plane_hit(t_ray ray, t_plane *pl, t_hit_record *rec)
{
	t_vec	ray2center;
	double	t;

	ray2center = vec_sub(ray.orig, pl->center);
	if (vec_dot(ray.dir, pl->normal) == 0)
		return (-1);
	t = vec_dot(vec_mul(ray2center, -1), pl->normal);
	t /= vec_dot(ray.dir, pl->normal);
	if (t <= 0)
		return (-1);
	rec->dist = t;
	rec->p = ray_at(ray, t);
	rec->normal = pl->normal;
	if (vec_dot(ray.dir, pl->normal) < 0)
		rec->normal = vec_mul(rec->normal, -1);
	rec->albedo = color_to_vec(pl->color);
	set_face_normal(ray, rec);
	return (1);
}

int	check_cylinder_hit(t_ray ray, t_cylinder *cy, t_hit_record *rec)
{
	double	half_b;
	double	discriminant;
	double	root;
	double	a;

	discriminant = cylinder_discriminant(ray, \
		vec_sub(ray.orig, cy->center), cy, &half_b);
	a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
	if (discriminant <= 0)
		return (-1);
	root = (-half_b - sqrt(discriminant)) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt(discriminant)) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (-1);
	}
	rec->dist = root;
	rec->p = ray_at(ray, root);
	rec->normal = cylinder_normal(ray, cy, rec);
	rec->albedo = color_to_vec(cy->color);
	set_face_normal(ray, rec);
	return (1);
}

double	cylinder_discriminant(t_ray ray, t_vec ray2center, \
								t_cylinder *cy, double *half_b)
{
	double	a;
	double	c;

	*half_b = vec_dot(ray.dir, ray2center) - (vec_dot(ray.dir, cy->axis) * \
		vec_dot(ray2center, cy->axis));
	a = vec_dot(ray.dir, ray.dir) - pow(vec_dot(ray.dir, cy->axis), 2);
	c = vec_dot(ray2center, ray2center) - \
		pow(vec_dot(ray2center, cy->axis), 2) - cy->rsquare;
	return (*half_b * *half_b - a * c);
}

t_vec	cylinder_normal(t_ray ray, t_cylinder *cy, t_hit_record *rec)
{
	t_vec	normal;
	double	m;

	normal = vec_sub(rec->p, cy->cap_point);
	m = vec_dot(ray.dir, vec_mul(cy->axis, rec->dist)) + \
		vec_dot(vec_sub(ray.orig, cy->center), cy->axis);
	normal = vec_sub(normal, vec_mul(cy->axis, m));
	normal = vec_normalize(normal);
	return (normal);
}
