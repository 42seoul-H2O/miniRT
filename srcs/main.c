/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/20 12:04:19 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

static void	chk_leak(void)
{
	system("leaks miniRT | grep leaked");
}

static void	prt_info(t_info *info)
{
	t_shapelst	*curr;
	t_plane		*plane;
	t_cylinder	*cylinder;
	t_sphere	*sphere;

	printf("Info.light{al_ratio, al_color, ambient, light_coor, brightness} : %.2f | %d | (%.2lf,%.2lf,%.2lf) | (%.2lf,%.2lf,%.2lf) | %.2f\n", \
		info->light.al_ratio, color_to_int(info->light.al_color), \
		info->light.ambient.x, info->light.ambient.y, info->light.ambient.z, \
		info->light.light_coor.x, info->light.light_coor.y, \
		info->light.light_coor.z, info->light.brightness);
	printf("Info.Camera{viewpoint, orient, fov} : (%.2lf,%.2lf,%.2lf) | (%.2lf,%.2lf,%.2lf) | %d\n", \
		info->camera.viewpoint.x, info->camera.viewpoint.y, \
		info->camera.viewpoint.z, info->camera.orient.x, \
		info->camera.orient.y, info->camera.orient.z, \
		info->camera.fov);
	printf("Viewport{width, height, focal_len, left_bot} : %.2f | %.2f | %.2f | (%.2lf,%.2lf,%.2lf)\n", \
		info->camera.vp.width, info->camera.vp.height, info->camera.vp.focal_len, \
		info->camera.vp.left_bot.x, info->camera.vp.left_bot.y, \
		info->camera.vp.left_bot.z);
	printf("\n---------- checking shape structures ----------\n");
	curr = info->shapes;
	while (curr)
	{
		if (curr->type == PLANE)
		{
			printf("curr node : plane\n");
			plane = (t_plane *)curr->shape;
			printf("{center coordinates | normal vector | color}: (%.2lf,%.2lf,%.2lf) | (%.2lf,%.2lf,%.2lf) | %d\n", \
			plane->center.x, plane->center.y, plane->center.z, \
			plane->normal.x, plane->normal.y, plane->normal.z, \
			color_to_int(plane->color));
		}
		else if (curr->type == CYLINDER)
		{
			printf("curr node : cylinder\n");
			cylinder = (t_cylinder *)curr->shape;
			printf("{center coordinates, normalized axis vector, diameter, height, color}: (%.2lf,%.2lf,%.2lf) | (%.2lf,%.2lf,%.2lf) | %.2f | %.2f | %d\n", \
			cylinder->center.x, cylinder->center.y, cylinder->center.z, \
			cylinder->axis.x, cylinder->axis.y, cylinder->axis.z, \
			cylinder->diameter, cylinder->height, color_to_int(cylinder->color));
		}
		else if (curr->type == SPHERE)
		{
			printf("curr node : sphere\n");
			sphere = (t_sphere *)curr->shape;
			printf("{center coordinates, diameter, color} : %.2lf,%.2lf,%.2lf | %.2lf | %d\n", \
			sphere->center.x, sphere->center.y, sphere->center.z, sphere->radius * 2, \
			color_to_int(sphere->color));
		}
		curr = curr->next;
	}
}

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

	atexit(chk_leak);
	if (argc != 2)
		puterr_and_exit("Usage : ./miniRT <.rt scene file>", "");
	scene_fd = open(argv[1], O_RDONLY);
	if (scene_fd == -1)
		puterr_and_exit("Failed to open scene file : ", argv[1]);
	init(&info, scene_fd);
	close(scene_fd);
	render(&info);
	prt_info(&info);
	mlx_put_image_to_window(info.mlx_ptr, info.win_ptr, info.data.img, 0, 0);
	mlx_loop(info.mlx_ptr);
	free_info(&info);
	return (0);
}
