/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:42:20 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/21 12:09:51 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_camera_matrix returns a matrix that translates and rotates a camera.
	It does not make sense to scale a camera.
	Thus scale.x = scale.y = scale.z = 1;
*/

#include "minirt.h"

static t_point	orientation_vec_to_radians(const t_vec orientation_vec);

t_matrix	*get_camera_matrix(const t_camera camera)
{
	t_matrix	*matrix;
	t_point		rotation;
	t_point		scale;

	rotation = orientation_vec_to_radians(camera.orient);
	scale = new_vector(1, 1, 1, 1);
	matrix = construct_basic_matrix(camera.viewpoint, rotation, scale);
	return (matrix);
}

static t_point	orientation_vec_to_radians(const t_vec orientation_vec)
{
	t_point	orientation_in_radians;
	double	x;
	double	y;
	double	z;

	x = orientation_vec.x;
	y = orientation_vec.y;
	z = orientation_vec.z;
	orientation_in_radians.x = atan(z / y);
	orientation_in_radians.y = atan(x / z);
	orientation_in_radians.z = atan(y / x);
	return (orientation_in_radians);
}

t_point	camera_coord_to_world_coord(const t_info *info, \
				t_point	point_in_camera_coordinate)
{
	t_matrix	*camera_matrix;
	t_point		point_in_world_coordinate;

	camera_matrix = info->camera.camera_to_world;
	point_in_world_coordinate = \
	multiply_matrix_by_4d_vec(camera_matrix, &point_in_camera_coordinate);
	return (point_in_world_coordinate);
}
