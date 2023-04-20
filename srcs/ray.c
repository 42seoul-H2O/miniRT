/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:27:28 by hocsong           #+#    #+#             */
/*   Updated: 2023/04/20 12:24:07 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

/*
	It is assumed that a virtual canvas is located perpendicular to 
		the xy plane of the viewing camera.
	Also assumed that the canvas is located 1 distance unit away from the camera.
	These assumptions are valid since canvas can be of any size and of any distance
		away as long as it produces desired fov.
	It is also assumed that a vertical field of view is determined by an image 
		ratio.
	Steps to generate a ray passing through a pixel in a raster space.
	1. Transform from the raster space to a continuous space.
	2. Transform from the continuous space to a Normalized Device Coordinate space.
	3. Transform from the NDC space to a screen space(range from -1 to 1). 
		Screen space's coordinates follow a camera's local coordinate system.
	4. Transform the space to have a range such that it produces a desired fov.
	5. Change coordinate system from one of the camera's to the world's.
	6. Calculate a ray's direction.
*/

#include "minirt.h"

static t_point	raster_to_screen(const t_info *info, int pixel_x, int pixel_y);
static t_point	camera_to_world(const t_info *info, \
				t_point	point_in_camera_coordinate);

t_ray	generate_ray(const t_info *info, int pixel_x, int pixel_y)
{
	t_point		screen_point;
	t_ray		ray;
	t_point		origin_in_world_coordinate;
	t_point		screen_point_in_world_coordinate;

	screen_point = raster_to_screen(info, pixel_x, pixel_y);
	origin_in_world_coordinate = camera_to_world(info, new_vector(0, 0, 0, 1));
	screen_point_in_world_coordinate = camera_to_world(info, screen_point);
	ray.orig = origin_in_world_coordinate;
	ray.dir = vec_sub(screen_point_in_world_coordinate, \
	origin_in_world_coordinate);
	ray.dir = vec_normalize(ray.dir);
	return (ray);
}

static t_point	raster_to_screen(const t_info *info, int pixel_x, int pixel_y)
{
	t_point			temp_point;
	const double	angle = PI * info->camera.fov / 360.0;

	temp_point.x = (((double) pixel_x + 0.5) / \
	(double) info->scr_width * 2 - 1) * tan(angle);
	temp_point.y = (((double) pixel_y + 0.5) / \
	(double) info->scr_height * 2 - 1) * -1 * tan(angle) / \
	((double) info->scr_width / (double) info->scr_height);
	temp_point.z = -1;
	temp_point.w = 1;
	return (temp_point);
}

static t_point	camera_to_world(const t_info *info, \
				t_point	point_in_camera_coordinate)
{
	t_matrix	*camera_matrix;
	t_point		point_in_world_coordinate;

	camera_matrix = get_camera_matrix(info->camera);
	point_in_world_coordinate = \
	multiply_matrix_by_4d_vec(camera_matrix, &point_in_camera_coordinate);
	destroy_matrix(camera_matrix);
	return (point_in_world_coordinate);
}
