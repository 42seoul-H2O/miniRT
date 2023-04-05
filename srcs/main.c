/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 16:39:10 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

static void	chk_leak(void)
{
	system("leaks miniRT | grep leak");
}

void	puterr_and_exit(char *err)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(err, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		scene_fd;

	atexit(chk_leak);
	if (argc != 2)
		puterr_and_exit("Usage : ./miniRT <.rt scene file>");
	scene_fd = open(argv[1], O_RDONLY);
	if (scene_fd == -1)
		puterr_and_exit("Failed to open scene file.");
	init(&info, scene_fd);
	close(scene_fd);
	render(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.data.img, 0, 0);
	mlx_loop(info.mlx_ptr);
	free_info(&info);
	return (0);
}
