/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackhole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:16:23 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/25 15:40:04 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shapelst	*get_blackhole(void)
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

t_color	get_blackhole_color(t_info *info)
{
	t_color	color;

	color.red = get_radiance(info, 255, RED, 1);
	color.green = get_radiance(info, 255, GREEN, 1);
	color.blue = get_radiance(info, 255, BLUE, 1);
	return (color);
}
