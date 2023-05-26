/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:07:16 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/24 15:21:08 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	new_color(unsigned char red, unsigned char green, unsigned char blue)
{
	t_color	result;

	result.red = red;
	result.green = green;
	result.blue = blue;
	return (result);
}

int	color_to_int(t_color color)
{
	return (red_to_int(color) | green_to_int(color) | blue_to_int(color));
}

int	red_to_int(t_color color)
{
	return ((int)color.red << 16);
}

int	blue_to_int(t_color color)
{
	return ((int)color.blue);
}

int	green_to_int(t_color color)
{
	return ((int)color.green << 8);
}
