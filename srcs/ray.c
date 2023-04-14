/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:40:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/14 12:43:41 by hyunjuki         ###   ########.fr       */
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
