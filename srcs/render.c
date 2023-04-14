/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:18:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/14 14:13:32 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(t_info *info)
{
	int		i;
	int		j;
	t_ray	ray;

	j = info->scr_height - 1;
	while (j >= 0)
	{
		i = 0;
		while (i < info->scr_width)
		{
			ray = get_primary_ray(info->camera, \
								(double)i / (info->scr_width - 1), \
								(double)j / (info->scr_height - 1));
			ft_mlx_pixel_put(&(info->data), i, info->scr_height - 1 - j, \
								ray_color(ray));
			++i;
		}
		--j;
	}
}

void	ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color_to_int(color);
}
