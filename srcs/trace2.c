/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 22:22:58 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/07 23:30:16 by hyunjuki         ###   ########.fr       */
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
	rec->normal = vec_normalize(vec_sub(rec->p, pl->center));
	rec->albedo = color_to_vec(pl->color);
	set_face_normal(ray, rec);
	return (1);
}
