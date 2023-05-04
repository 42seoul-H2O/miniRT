/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_diffuse_radiance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:53:49 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/04 16:54:54 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	get_diffuse_radiance(t_info *info, \
				int albedo, t_point point_on_surface, double cos_theta)
{
	double	diffuse_radiance;

	point_on_surface.w = point_on_surface.w;
	diffuse_radiance = info->light.normalized_radiance * albedo * \
	cos_theta;
	return (diffuse_radiance);
}
