/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:40:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/15 21:36:23 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	new_ray(t_point orig, t_vec dir)
{
	t_ray	result;

	result.orig = orig;
	result.dir = dir;
	return (result);
}

t_point	ray_at(t_ray ray, t_scalar s)
{
	t_point	dst;

	dst = vec_sum(ray.orig, vec_mul(ray.dir, s));
	return (dst);
}

t_ray	get_primary_ray(t_camera cam, t_scalar w, t_scalar h)
{
	t_ray	result;
	t_vec	direction;

	result.orig = cam.viewpoint;
	direction = vec_sum(cam.vp.left_bot, vec_mul(cam.vp.horizontal, w));
	direction = vec_sum(direction, vec_mul(cam.vp.vertical, h));
	direction = vec_sub(direction, cam.viewpoint);
	result.dir = vec_normalize(direction);
	return (result);
}

t_color	get_ray_color(t_ray ray, t_info *info)
{
	int	ray_color;

	ray_color = check_ray_hit(ray, info);
	if (ray_color != -1)
		return (new_color((ray_color >> 16) & 0xFF, \
				(ray_color >> 8) & 0xFF, ray_color & 0xFF));
	return (default_ray_color(ray));
}

t_color	default_ray_color(t_ray ray)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = 0.5 * (ray.dir.y + 1.0);
	r = (1.0 - t) * 255.999 + t * 102.999;
	g = (1.0 - t) * 255.999 + t * 153.999;
	b = (1.0 - t) * 255.999 + t * 255.999;
	return (new_color(r, g, b));
}

