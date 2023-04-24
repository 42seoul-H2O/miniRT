/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:24:43 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/24 15:46:53 by hocsong          ###   ########seoul.kr  */
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
void		puterr_and_exit(char *err, char *target);

/*
** color.c
*/
t_color		new_color(unsigned char red, \
					unsigned char green, unsigned char blue);
int			color_to_int(t_color color);
int			red_to_int(t_color color);
int			blue_to_int(t_color color);
int			green_to_int(t_color color);

/*
** ft_atof.c
*/
double		ft_atof(const char *str);

/*
** init.c
*/
void		init(t_info *info, int scene_fd);
void		free_info(t_info *info);

/*
** key_hook.c
*/
int			exit_hook(void *arg);
int			esc_key_hook(int key);

/*
** parser_main.c
*/
void		parse_scene(t_info *info, int scene_fd);
void		change_white_spaces(char *str);
void		parse_tokens(t_info *info, char **tokens);
int			token_len(char **tokens);
void		free_tokens(char **tokens);

/*
** parser_ambient.c
*/
void		parse_ambient_light(t_info *info, char **tokens);
void		parse_am_light_ratio(t_info *info, char *token);
void		parse_am_light_color(t_info *info, char *token);
void		check_rgb_token(char *str, char **tokens);

/*
** parser_camera.c
*/
void		parse_camera_info(t_info *info, char **tokens);
t_point		parse_coordinates(char *token);
t_vec		parse_normal_orient_vec(char *token);
int			ft_cinstr(int c, char *str);
int			parse_camera_fov(char *token);

/*
** parser_cylinder.c
*/
void		parse_cylinder(t_info *info, char **tokens);
double		parse_diameter_or_height(char *token);
t_color		parse_shape_color(char *token);

/*
** parser_light.c
*/
void		parse_light_info(t_info *info, char **tokens);
void		parse_brightness(t_info *info, char *token);

/*
** parser_plane.c
*/
void		parse_plane(t_info *info, char **tokens);

/*
** parser_sphere.c
*/
void		parse_sphere(t_info *info, char **tokens);

/*
** render.c
*/
void		render(t_info *info);
void		ft_mlx_pixel_put(t_imgdata *data, int x, int y, t_color color);

/*
** vector_oper1.c
*/
t_vec		new_vector(double x, double y, double z, double w);
t_vec		vec_sum(t_vec v1, t_vec v2);
double		vec_dot(t_vec v1, t_vec v2);
t_vec		vec_prod(t_vec v1, t_vec v2);
double		vec_size(t_vec v1);

/*
** vector_oper2.c
*/
t_vec		vec_mul(t_vec vector, t_scalar scalar);
t_vec		vec_sub(t_vec v1, t_vec v2);
t_vec		vec_normalize(t_vec vector);

/*
** shapelst_oper1.c
*/
t_shapelst	*new_node(int shape_type, void *shape);
void		free_node(t_shapelst *node);
void		free_shapelst(t_shapelst *head);
t_shapelst	*get_last(t_shapelst *node);
void		node_append(t_info *info, t_shapelst *node);

/*
** matrix_oper1.c
*/
t_matrix	*init_matrix(int row_dimension, int column_dimension);
void		destroy_matrix(t_matrix *matrix);
double		get_matrix_item(t_matrix *matrix, int row_index, int column_index);
void		set_matrix_item(t_matrix *matrix, int row_index, int column_index, \
			double entry);
t_matrix	*construct_basic_matrix(t_point translation, t_point rotation, \
			t_point scale);

/*
** matrix_oper2.c
*/
t_matrix	*multiply_matrices(t_matrix *matrix1, t_matrix *matrix2);
t_vec		multiply_matrix_by_4d_vec(t_matrix *matrix, t_vec *vec);

/*
** matrix_oper3.c
*/
void		print_matrix(t_matrix *matrix);

/*
** camera.c
*/

t_matrix	*get_camera_matrix(const t_camera camera);
t_point		ray_to_point(t_ray ray, double t);
t_point		camera_coord_to_world_coord(const t_info *info, \
			t_point	point_in_camera_coordinate);

/*
** sphere.c
*/

t_color				get_color_sphere(t_sphere sphere, t_ray ray);
double				get_intersection_sphere(t_sphere sphere, t_ray ray);
t_spherical_coord	get_spherical_coord(t_point point);

/*
** ray.c
*/

t_ray				get_ray(const t_info *info, int pixel_x, int pixel_y);
t_point				ray_to_point(t_ray ray, double t);

#endif