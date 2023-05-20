/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_radiance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:49 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/20 19:14:05 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_ambient_radiance(t_info *info, int albedo, int color)
{
	double	ambient_radiance;

	ambient_radiance = 0;
	if (color == RED)
		ambient_radiance = albedo / 255.0f * info->light.ambient_color.red \
		* info->light.ambient_normalized_radiance;
	else if (color == GREEN)
		ambient_radiance = albedo / 255.0f * info->light.ambient_color.green \
		* info->light.ambient_normalized_radiance;
	else if (color == BLUE)
		ambient_radiance = albedo / 255.0f * info->light.ambient_color.blue \
		* info->light.ambient_normalized_radiance;
	else
		puterr_and_exit("Invalid color : ", "");
	return (ambient_radiance);
}

double	get_diffuse_radiance(t_info *info, \
				int albedo, t_point point_on_surface, double cos_theta)
{
	double	diffuse_radiance;

	point_on_surface.w = point_on_surface.w;
	diffuse_radiance = info->light.normalized_radiance * albedo * \
	cos_theta;
	return (diffuse_radiance);
}
