/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:47:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/18 15:54:29 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_ray_hit(t_ray ray, t_info *info, t_hit_record *rec)
{
	t_shapelst	*curr;
	int			ret;

	curr = info->shapes;
	ret = -1;
	while (curr)
	{
		if (curr->type == SPHERE)
			ret = check_sphere_hit(ray, curr->shape, rec);
		else if (curr->type == PLANE)
			ret = -1;
		else if (curr->type == CYLINDER)
			ret = -1;
		if (ret != -1)
			return (ret);
		curr = curr->next;
	}
	return (-1);
}

int	check_sphere_hit(t_ray ray, t_sphere *sp, t_hit_record *rec)
{
	t_vec	ray2center;
	double	half_b;
	double	discreminant;
	double	root;

	ray2center = vec_sub(ray.orig, sp->center);
	half_b = vec_dot(ray2center, ray.dir);
	discreminant = half_b * half_b - (vec_dot(ray.dir, ray.dir) \
					* (vec_dot(ray2center, ray2center) - sp->rsquare));
	if (discreminant <= 0)
		return (-1);
	root = (-half_b - sqrt(discreminant)) / vec_dot(ray.dir, ray.dir);
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt(discreminant)) / vec_dot(ray.dir, ray.dir);
		if (root < rec->tmin || root > rec->tmax)
			return (-1);
	}
	rec->dist = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_mul(vec_sub(rec->p, sp->center), 1 / sp->radius);
	set_face_normal(ray, rec);
	return (get_sphere_color(ray, sp, root));
}

int	get_sphere_color(t_ray ray, t_sphere *sp, double lrr)
{
	t_vec	normal;

	normal = ray_at(ray, lrr);
	normal = vec_sub(normal, sp->center);
	normal = vec_normalize(normal);
	normal.x += 1;
	normal.y += 1;
	normal.z += 1;
	normal = vec_mul(normal, 255 * 0.5);
	return (color_to_int(new_color(normal.x, normal.y, normal.z)));
}

void	set_face_normal(t_ray ray, t_hit_record *rec)
{
	if (vec_dot(ray.dir, rec->normal) < 0)
		rec->front_face = 1;
	else
		rec->front_face = 0;
	if (!rec->front_face)
		rec->normal = vec_mul(rec->normal, -1);
}
