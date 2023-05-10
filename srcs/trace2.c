/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:58 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/10 21:17:35 by hyunjuki         ###   ########.fr       */
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
	t_vec	ray2center;
	double	half_b;
	double	discriminant;
	double	root;

	ray2center = vec_sub(ray.orig, cy->center);
	half_b = vec_dot(ray2center, ray.dir);
	discriminant = half_b * half_b - (vec_dot(ray.dir, ray.dir) \
					* (vec_dot(ray2center, ray2center) - sp->rsquare));
	if (discriminant <= 0)
		return (-1);
	root = (-half_b - sqrt(discriminant)) / A;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt(discriminant)) / A;
		if (root < rec->tmin || root > rec->tmax)
			return (-1);
	}
	rec->dist = root;
	rec->p = ray_at(ray, root);
	rec->normal = 0;
	rec->albedo = color_to_vec(cy->color);
	set_face_normal(ray, rec);
	return (1);
}

double	cylinder_discriminant(t_ray ray, t_cylinder *cy)
{
	
}
