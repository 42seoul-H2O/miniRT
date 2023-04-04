/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/04 16:53:28 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void *arg)
{
	(void) arg;
	exit(0);
}

int	esc_key_hook(int key)
{
	if (key == KEY_ESC)
		exit_hook(NULL);
	return (0);
}

int	main(void)
{
	t_info	info;

	info.mlx_ptr = mlx_init();
	info.win_ptr = mlx_new_window(info.mlx_ptr, 640, 320, "miniRT");
	mlx_key_hook(info.win_ptr, esc_key_hook, NULL);
	mlx_hook(info.win_ptr, X_EVENT_KEY_EXIT, 0, exit_hook, NULL);
	mlx_loop(info.mlx_ptr);
	return (0);
}
