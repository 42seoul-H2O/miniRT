/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/14 18:12:55 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/19 12:36:03 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double		get_intersection_t(t_ray ray, t_shapelst *shapelst);
static t_shapelst	*get_blackhole(void);
static int			is_shadowed(t_info *info, \
					t_point point_to_render, t_shapelst *shape);

t_shapelst	*get_visible_shape(t_info *info, t_ray ray)
{
	double		t;
	double		nearest_t;
	t_shapelst	*nearest_shape;
	t_shapelst	*shapelst;

	nearest_t = DOUBLE_MAX;
	nearest_shape = NULL;
	shapelst = info->shapes;
	while (shapelst)
	{
		t = get_intersection_t(ray, shapelst);
		if (t < nearest_t && 0 < t)
		{
			nearest_t = t;
			nearest_shape = shapelst;
		}
		shapelst = shapelst->next;
	}
	if (nearest_shape && is_shadowed(info, ray_to_point(ray, t), nearest_shape))
		return (get_blackhole());
	return (nearest_shape);
}

static double	get_intersection_t(t_ray ray, t_shapelst *shapelst)
{
	double	t;

	t = DOUBLE_MAX;
	if (shapelst->type == SPHERE)
		t = get_intersection_sphere(*((t_sphere *) shapelst->shape), ray);
	else if (shapelst->type == PLANE)
		t = get_intersection_plane(*((t_plane *) shapelst->shape), ray);
	else if (shapelst->type == CYLINDER)
		t = get_intersection_cylinder(*((t_cylinder *) shapelst->shape), ray);
	return (t);
}

static t_shapelst	*get_blackhole(void)
{
	t_shapelst	*blackhole;

	blackhole = malloc(sizeof (t_shapelst));
	if (!blackhole)
		puterr_and_exit("Failed to allocate memory : ", "Blackhole");
	blackhole->next = NULL;
	blackhole->shape = NULL;
	blackhole->type = BLACKHOLE;
	return (blackhole);
}

static int	is_shadowed(t_info *info, \
			t_point point_to_render, t_shapelst *shape)
{
	// const double	shadow_bias = 0.001;
	double			t;
	t_ray			ray;
	t_shapelst		*shapelst;

	t = -1;
	// if (shape->type == SPHERE)
	// get_normal_sphere(*(t_sphere *)shape->shape, point_to_render);
	// if (shape->type == PLANE)
	if (shape->type == CYLINDER)
		ray.orig = vec_sum(get_normal_sphere(\
		*(t_sphere *)shape->shape, point_to_render), ray.orig);
	ray.orig = point_to_render;
	ray.dir = vec_sub(info->light.light_coor, ray.orig);
	ray.dir = vec_normalize(ray.dir);
	shapelst = info->shapes;
	while (shapelst)
	{
		if (shapelst->type == SPHERE)
			t = get_intersection_sphere(*((t_sphere *) shapelst->shape), ray);
		else if (shapelst->type == PLANE)
			t = get_intersection_plane(*((t_plane *) shapelst->shape), ray);
		else if (shapelst->type == CYLINDER)
			t = get_intersection_cylinder(\
			*((t_cylinder *) shapelst->shape), ray);
		if (0 < t)
			return (1);
		shapelst = shapelst->next;
	}
	return (0);
}