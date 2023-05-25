/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackhole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:16:23 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/25 17:18:14 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shapelst	*get_blackhole(t_shapelst *shapelst)
{
	t_shapelst	*blackhole;
	t_color		color;

	blackhole = malloc(sizeof (t_shapelst));
	if (!blackhole)
		puterr_and_exit("Failed to allocate memory : ", "Blackhole");
	blackhole->next = NULL;
	blackhole->type = BLACKHOLE;
	blackhole->shape = malloc(sizeof (t_blackhole));
	if (!blackhole->shape)
		puterr_and_exit("Failed to allocate memory : ", "Blackhole");
	if (shapelst->type == SPHERE)
		color = ((t_sphere *)shapelst->shape)->color;
	if (shapelst->type == PLANE)
		color = ((t_plane *)shapelst->shape)->color;
	if (shapelst->type == CYLINDER)
		color = ((t_cylinder *)shapelst->shape)->color;
	((t_blackhole *)blackhole->shape)->color = color;
	return (blackhole);
}

t_color	get_blackhole_color(t_info *info, t_blackhole *blackhole)
{
	t_color	color;

	color.red = get_radiance(info, blackhole->color.red, RED, 0);
	color.green = get_radiance(info, blackhole->color.green, GREEN, 0);
	color.blue = get_radiance(info, blackhole->color.red, BLUE, 0);
	return (color);
}
