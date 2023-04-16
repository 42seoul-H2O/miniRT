/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:27:28 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/16 17:15:25 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	generate_ray(const t_info *info, int pixel_x, int pixel_y)
{
	double			x; // 카메라의 coordinate system을 사용.
	double			y;
	const double	PI = 3.14159265359;

	x = ((double) pixel_x + 0.5) \
	/ (double) info->scr_width * tan(PI * (double) info->camera.fov / 180.0);
	y = ((double) pixel_y + 0.5) \
	/ (double) info->scr_height / (2.0 * (double) info->scr_width \
	/ (double) info->scr_height);
}
