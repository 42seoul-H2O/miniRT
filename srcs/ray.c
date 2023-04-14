/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:40:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/14 13:25:50 by hyunjuki         ###   ########.fr       */
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

	dst = vec_sum(ray.dir, vec_mul(ray.orig, s));
	return (dst);
}

t_ray	get_primary_ray(t_camera cam, t_scalar h, t_scalar w)
{
	t_ray	result;
	t_vec	direction;

	result.orig = cam.viewpoint;
	direction = vec_sum(cam.vp.left_bot, vec_mul(cam.vp.horizontal, h));
	direction = vec_sum(direction, vec_mul(cam.vp.vertical, w));
	direction = vec_sub(direction, cam.viewpoint);
	result.dir = vec_normalize(direction);
	return (result);
}

t_color	ray_color(t_ray ray)
{
	double			t;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	t = 0.5 * (ray.dir.y * 1.0);
	r = (1. - t) * 255 + t * 255 * 0.5;
	g = (1. - t) * 255 + t * 255 * 0.7;
	b = (1. - t) * 255 + t * 255;
	return (new_color(r, g, b));
}
