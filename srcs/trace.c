/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:47:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/10 21:35:53 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_ray_hit(t_ray ray, t_info *info, t_hit_record *rec)
{
	t_shapelst		*curr;
	t_hit_record	temp;
	int				hit;

	curr = info->shapes;
	hit = -1;
	temp = *rec;
	while (curr)
	{
		if (check_object_hit(ray, curr, &temp) != -1)
		{
			temp.tmax = temp.dist;
			*rec = temp;
			hit = 1;
		}
		curr = curr->next;
	}
	return (hit);
}

int	check_object_hit(t_ray ray, t_shapelst *node, t_hit_record *rec)
{
	if (node->type == SPHERE)
	{
		return (check_sphere_hit(ray, node->shape, rec));
	}
	else if (node->type == PLANE)
	{
		return (check_plane_hit(ray, node->shape, rec));
	}
	else if (node->type == CYLINDER)
	{
		return (check_cylinder_hit(ray, node->shape, rec));
	}
	return (-1);
}

int	check_sphere_hit(t_ray ray, t_sphere *sp, t_hit_record *rec)
{
	t_vec	ray2center;
	double	half_b;
	double	discriminant;
	double	root;

	ray2center = vec_sub(ray.orig, sp->center);
	half_b = vec_dot(ray2center, ray.dir);
	discriminant = half_b * half_b - (vec_dot(ray.dir, ray.dir) \
					* (vec_dot(ray2center, ray2center) - sp->rsquare));
	if (discriminant <= 0)
		return (-1);
	root = (-half_b - sqrt(discriminant)) / vec_dot(ray.dir, ray.dir);
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt(discriminant)) / vec_dot(ray.dir, ray.dir);
		if (root < rec->tmin || root > rec->tmax)
			return (-1);
	}
	rec->dist = root;
	rec->p = ray_at(ray, root);
	rec->normal = vec_mul(vec_sub(rec->p, sp->center), 1 / sp->radius);
	rec->albedo = color_to_vec(sp->color);
	set_face_normal(ray, rec);
	return (1);
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
