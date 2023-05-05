/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:42:20 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/05 17:12:13 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_camera_matrix returns a matrix that translates and rotates a camera.
	It does not make sense to scale a camera.
	Thus scale.x = scale.y = scale.z = 1;
*/

/*
	get_camera_rotation_matrix calculates a suitable rotation matrix based on a
	given orientation vector. It does so by calculating beta and theta where
	beta corresponds to the angle of rotation with respect to the y axis and
	theta corresponds to the angle of rotation with respect to the z axis.
	It is assumed that axes are extrinsically rotated by beta first and intrinsically
	rotated by theta.
*/

#include "minirt.h"

t_matrix	*get_camera_matrix(const t_camera camera)
{
	const double	phi = atan2(camera.orient.x, camera.orient.z);
	const double	theta = acos(camera.orient.y) - PI / 2;
	t_matrix		*matrix;

	matrix = init_matrix(4, 4);
	matrix->data[0] = cos(phi);
	matrix->data[1] = sin(phi) * sin(theta);
	matrix->data[2] = sin(phi) * cos(theta);
	matrix->data[3] = camera.viewpoint.x;
	matrix->data[4] = 0;
	matrix->data[5] = cos(theta);
	matrix->data[6] = -1 * sin(theta);
	matrix->data[7] = camera.viewpoint.y;
	matrix->data[8] = -1 * sin(phi);
	matrix->data[9] = cos(phi) * sin(theta);
	matrix->data[10] = cos(phi) * cos(theta);
	matrix->data[11] = camera.viewpoint.z;
	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1;
	return (matrix);
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
