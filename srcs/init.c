/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:29:32 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 15:45:12 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init(t_info *info, int scene_fd)
{
	info->mlx_ptr = mlx_init();
	if (!(info->mlx_ptr))
		puterr_and_exit("Failed to init MinlLibX.");
	info->win_ptr = mlx_new_window(info->mlx_ptr, \
		WINDOW_WIDTH, WINDOW_HEIGHT, "miniRT");
	if (!(info->win_ptr))
		puterr_and_exit("Failed to init Window");
	mlx_key_hook(info->win_ptr, esc_key_hook, NULL);
	mlx_hook(info->win_ptr, X_EVENT_KEY_EXIT, 0, exit_hook, NULL);
	parse_scene(info, scene_fd);
}

void	free_info(t_info *info)
{
	info->height = 0;
	return ;
}
