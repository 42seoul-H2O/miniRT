/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:29:32 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 17:56:56 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init(t_info *info, int scene_fd)
{
	info->camera.is_camera_set = 0;
	info->light.is_ambient_set = 0;
	info->light.is_light_set = 0;
	info->mlx_ptr = mlx_init();
	if (!(info->mlx_ptr))
		puterr_and_exit("Failed to init MinlLibX.", "");
	info->win_ptr = mlx_new_window(info->mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (!(info->win_ptr))
		puterr_and_exit("Failed to init Window.", "");
	mlx_key_hook(info->win_ptr, esc_key_hook, NULL);
	mlx_hook(info->win_ptr, X_EVENT_KEY_EXIT, 0, exit_hook, NULL);
	info->data.img = mlx_new_image(info->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(info->data.img))
		puterr_and_exit("Failed to init Image.", "");
	info->data.addr = mlx_get_data_addr(info->data.img, &(info-> \
		data.bits_per_pixel), &(info->data.line_length), &(info->data.endian));
	if (!(info->data.addr))
		puterr_and_exit("Failed to get Image address.", "");
	parse_scene(info, scene_fd);
}

void	free_info(t_info *info)
{
	mlx_destroy_image(info->mlx_ptr, info->data.img);
	mlx_destroy_window(info->mlx_ptr, info->win_ptr);
	return ;
}
