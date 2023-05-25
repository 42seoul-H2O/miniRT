/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:18:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/25 21:46:12 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color		get_color(t_info *info, int pixel_x, int pixel_y);

void	render(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->scr_width)
	{
		j = 0;
		while (j < info->scr_height)
		{
			if (i == 1280 && j == 720)
				write(1, "debugging\n", 10);
			ft_mlx_pixel_put(&(info->data), i, j, get_color(info, i, j));
			j++;
		}
		i++;
	}
}

static t_color	get_color(t_info *info, int pixel_x, int pixel_y)
{
	t_ray		ray;
	t_shapelst	*visible_shape;
	t_color		color;

	ray = get_ray(info, pixel_x, pixel_y);
	visible_shape = get_visible_shape(info, ray);
	if (visible_shape && visible_shape->type == SPHERE)
		color = get_color_sphere(\
			info, *((t_sphere *) visible_shape->shape), ray);
	else if (visible_shape && visible_shape->type == PLANE)
		color = get_color_plane(\
			info, *((t_plane *) visible_shape->shape), ray);
	else if (visible_shape && visible_shape->type == CYLINDER)
		color = get_color_cylinder(\
			info, *((t_cylinder *) visible_shape->shape), ray);
	else if (visible_shape)
	{
		color = get_blackhole_color(\
		info, (t_blackhole *)visible_shape->shape);
		free(visible_shape->shape);
		free(visible_shape);
	}
	else
		color = get_blackhole_color(info, (void *)0);
	return (color);
}

void	ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color_to_int(color);
}
