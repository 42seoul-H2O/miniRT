/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:24:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 16:36:06 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "constants.h"
# include "structures.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
** main.c
*/
void	puterr_and_exit(char *err);

/*
** color.c
*/
t_color	new_color(unsigned char red, unsigned char green, unsigned char blue);
int		color_to_int(t_color color);
int		red_to_int(t_color color);
int		blue_to_int(t_color color);
int		green_to_int(t_color color);

/*
** ft_atof.c
*/
double	ft_atof(const char *str);

/*
** init.c
*/
void	init(t_info *info, int scene_fd);
void	free_info(t_info *info);

/*
** key_hook.c
*/
int		exit_hook(void *arg);
int		esc_key_hook(int key);

/*
** parser.c
*/
void	parse_scene(t_info *info, int scene_fd);

/*
** render.c
*/
void	render(t_info *info);
void	ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color);

#endif