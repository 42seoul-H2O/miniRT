/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:18:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/21 10:47:59 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_color		get_color(t_info *info, int pixel_x, int pixel_y);
static t_shapelst	*get_visible_shape(t_info *info, int pixel_x, int pixel_y);

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
			ft_mlx_pixel_put(&(info->data), i, j, get_color(info, i, j));
			j++;
		}
		i++;
	}
}

static t_color	get_color(t_info *info, int pixel_x, int pixel_y)
{
	t_color		color;
	t_shapelst	*visible_shape;

	visible_shape = get_visible_shape(info, pixel_x, pixel_y);
	if (!visible_shape)
		color = new_color(135, 206, 250);
	else
	{
		// if (visible_shape->type == SPHERE)
		color = get_color_sphere(*((t_sphere *) visible_shape->shape), \
		pixel_x, pixel_y);
	}
	return (color);
}

static t_shapelst	*get_visible_shape(t_info *info, int pixel_x, int pixel_y)
{
	double		t;
	double		nearest_t;
	t_shapelst	*nearest_shape;
	t_shapelst	*shapelst;

	t = DOUBLE_MAX;
	nearest_t = DOUBLE_MAX;
	nearest_shape = NULL;
	shapelst = info->shapes;
	while (shapelst)
	{
		if (shapelst->type == SPHERE)
		{
			t = get_intersection_sphere(*((t_sphere *) shapelst->shape), \
			get_ray(info, pixel_x, pixel_y));
			if (t < nearest_t)
			{
				nearest_t = t;
				nearest_shape = shapelst;
			}
		}
		shapelst = shapelst->next;
	}
	return (nearest_shape);
}

void	ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color_to_int(color);
}
