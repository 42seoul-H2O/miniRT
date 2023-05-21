/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 20:42:20 by hocsong           #+#    #+#             */
/*   Updated: 2023/05/21 18:26:56 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	get_camera_matrix returns a matrix that translates and rotates a camera.
	It does not make sense to scale a camera.
	Thus scale.x = scale.y = scale.z = 1;
*/

/*
	get_camera_matrix calculates a suitable rotation matrix based on a
	given orientation vector. It does so by calculating phi and theta where
	beta corresponds to the angle of rotation with respect to the y axis and
	theta corresponds to the angle of rotation with respect to the local z axis.
	It is assumed that axes are extrinsically rotated by phi first and intrinsically
	rotated by theta.
	
	when calculating phi, orient.x and orient.y are multiplied by -1 as z axis of a camera
	must be facing opposite direction of the camera orientation due to the fact
	that z axis is flipped by convention.
*/

#include "minirt.h"

t_matrix	*get_camera_matrix(const t_camera camera)
{
	t_matrix	*matrix;

	matrix = construct_basic_matrix(camera.viewpoint, \
	vec_mul(camera.orient, -1), 'Z');
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

void	translate_camera(t_camera *camera, t_point translation)
{
	camera->viewpoint = vec_sum(camera->orient, translation);
}

void	rotate_camera(t_camera *camera, t_point new_orientation)
{
	camera->orient = new_orientation;
}
