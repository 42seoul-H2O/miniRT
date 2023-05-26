/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/26 13:00:30 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	puterr_and_exit(char *err, char *target)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(err, 2);
	ft_putendl_fd(target, 2);
	exit(1);
}

int	main(int argc, char **argv)
{
	t_info	info;
	int		scene_fd;

	if (argc != 2)
		puterr_and_exit("Usage : ./miniRT <.rt scene file>", "");
	scene_fd = open(argv[1], O_RDONLY);
	if (scene_fd == -1)
		puterr_and_exit("Failed to open scene file : ", argv[1]);
	init(&info, scene_fd);
	close(scene_fd);
	render(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.data.img, 0, 0);
	mlx_loop(info.mlx_ptr);
	free_info(&info);
	return (0);
}
