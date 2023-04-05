/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:59:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 16:30:38 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_scene(t_info *info, int scene_fd)
{
	info->camera.fov = 0;
	info->light.al_color = new_color(0, 0, 1);
	info->light.al_ratio = 0.1;
	info->light.brightness = 0.2;
	(void)scene_fd;
}
