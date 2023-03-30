/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/03/30 21:39:54 by hyunjuki         ###   ########.fr       */
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
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 640, 320, "miniRT");
	mlx_key_hook(win_ptr, esc_key_hook, NULL);
	mlx_hook(win_ptr, X_EVENT_KEY_EXIT, 0, exit_hook, NULL);
	mlx_loop(mlx_ptr);
	return (0);
}
