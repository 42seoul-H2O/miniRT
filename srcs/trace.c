/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:47:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/15 21:33:22 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_ray_hit(t_ray ray, t_info *info)
{
	t_shapelst	*curr;
	int			ret;

	curr = info->shapes;
	ret = -1;
	while (curr)
	{
		if (curr->type == SPHERE)
			ret = check_sphere_hit(ray, curr->shape);
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

int	check_sphere_hit(t_ray ray, t_sphere *sp)
{
	t_vec	ray2center;
	double	a;
	double	b;
	double	c;
	double	discriminant;

	ray2center = vec_sub(ray.orig, sp->center);
	a = vec_dot(ray.dir, ray.dir);
	b = 2.0 * vec_dot(ray2center, ray.dir);
	c = vec_dot(ray2center, ray2center) - sp->rsquare;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	return (get_sphere_color(ray, sp, (-b - sqrt(discriminant)) / (2.0 * a)));
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
