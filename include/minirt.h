/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:24:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 19:22:50 by hyunjuki         ###   ########.fr       */
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
# include <math.h>
# include <stdio.h>

/*
** main.c
*/
void	puterr_and_exit(char *err, char *target);

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
** parser_main.c
*/
void	parse_scene(t_info *info, int scene_fd);
void	change_white_spaces(char *str);
void	parse_tokens(t_info *info, char **tokens);
int		token_len(char **tokens);

/*
** parser_ambient.c
*/
void	parse_ambient_light(t_info *info, char **tokens);

/*
** parser_camera.c
*/
void	parse_camera_info(t_info *info, char **tokens);

/*
** parser_cylinder.c
*/
void	parse_cylinder(t_info *info, char **tokens);

/*
** parser_light.c
*/
void	parse_light_info(t_info *info, char **tokens);

/*
** parser_plane.c
*/
void	parse_plane(t_info *info, char **tokens);

/*
** parser_sphere.c
*/
void	parse_sphere(t_info *info, char **tokens);

/*
** render.c
*/
void	render(t_info *info);
void	ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color);

/*
** vector_oper1.c
*/
t_vec	new_vector(double x, double y, double z);
t_vec	vec_sum(t_vec v1, t_vec v2);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_prod(t_vec v1, t_vec v2);
double	vec_size(t_vec v1);

/*
** vector_oper2.c
*/
t_vec	vec_mul(t_vec vector, t_scalar scalar);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_normalize(t_vec vector);

#endif