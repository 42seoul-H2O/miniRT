/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:25:48 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/04 18:40:37 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

static void	chk_leak(void)
{
	system("leaks miniRT | grep leak");
}

static void	test_atof(void)
{
	printf("-----------Testing ft_atof-----------\n");
	printf("lib: %lf, ft: %lf\n", atof("123.4312354"), ft_atof("123.4312354"));
	printf("lib: %lf, ft: %lf\n", atof("-143.25456"), ft_atof("-143.25456"));
	printf("lib: %lf, ft: %lf\n", atof("0.12131"), ft_atof("0.12131"));
	printf("lib: %lf, ft: %lf\n", atof("-0.7763"), ft_atof("-0.7763"));
	printf("lib: %lf, ft: %lf\n", atof("42.42424242"), ft_atof("42.42424242"));
	printf("lib: %lf, ft: %lf\n", atof("-42.42424242"), ft_atof("-42.42424242"));
	printf("lib: %lf, ft: %lf\n", atof("42"), ft_atof("42"));
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
	mlx_loop(info.mlx_ptr);
	test_atof();
	close(scene_fd);
	free_info(&info);
	return (0);
}
