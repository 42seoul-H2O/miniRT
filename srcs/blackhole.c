/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blackhole.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:16:23 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/20 19:18:53 by hocsong          ###   ########seoul.kr  */
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

	color.red = get_ambient_radiance(info, 255, RED);
	color.green = get_ambient_radiance(info, 255, GREEN);
	color.blue = get_ambient_radiance(info, 255, BLUE);
	return (color);
}
