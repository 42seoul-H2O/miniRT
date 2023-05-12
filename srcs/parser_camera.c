/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:49 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/12 15:27:33 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera_info(t_info *info, char **tokens)
{
	if (info->camera.is_camera_set)
		puterr_and_exit("Cannot be set camera twice.", "");
	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for setting camera.", "");
	info->camera.viewpoint = parse_coordinates(tokens[0]);
	info->camera.orient = parse_normal_orient_vec(tokens[1]);
	info->camera.vfov = parse_camera_fov(tokens[2], info->aspect_ratio);
	info->camera.vp.height = 2.0 * tan((info->camera.vfov * PI / 180) / 2.0);
	info->camera.vp.width = info->camera.vp.height * info->aspect_ratio;
	info->camera.vp.focal_len = 1.0;
	set_viewport_plane(&(info->camera));
	info->camera.is_camera_set = 1;
}

void	set_viewport_plane(t_camera *cam)
{
	t_vec	vup;
	t_vec	temp;
	t_vec	orient;

	vup = new_vector(0, 1, 0);
	orient = vec_mul(cam->orient, -1);
	temp = vec_prod(vup, orient);
	cam->vp.horizontal = vec_normalize(vec_mul(temp, cam->vp.width));
	temp = vec_prod(orient, temp);
	cam->vp.vertical = vec_normalize(vec_mul(temp, cam->vp.height));
	cam->vp.left_bot = vec_sub(cam->viewpoint, \
								vec_mul(cam->vp.horizontal, 0.5));
	cam->vp.left_bot = vec_sub(cam->vp.left_bot, \
								vec_mul(cam->vp.vertical, 0.5));
	cam->vp.left_bot = vec_sub(cam->vp.left_bot, orient);
}

t_point	parse_coordinates(char *token)
{
	int		i;
	char	**temp;
	t_point	result;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || ft_cinstr(token[i], ",.-")))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	temp = ft_split(token, ',');
	if (!temp)
		puterr_and_exit("Cannot split coordinates token. : ", token);
	if (token_len(temp) != 3)
		puterr_and_exit("Invalid coordinates token. : ", token);
	result.x = ft_atof(temp[0]);
	result.y = ft_atof(temp[1]);
	result.z = ft_atof(temp[2]);
	free_tokens(temp);
	return (result);
}

t_vec	parse_normal_orient_vec(char *token)
{
	int		i;
	char	**temp;
	t_vec	result;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || ft_cinstr(token[i], ",.-")))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	temp = ft_split(token, ',');
	if (!temp)
		puterr_and_exit("Cannot split normal orient vector token. : ", token);
	if (token_len(temp) != 3)
		puterr_and_exit("Invalid normal orient vector token. : ", token);
	result.x = ft_atof(temp[0]);
	result.y = ft_atof(temp[1]);
	result.z = ft_atof(temp[2]);
	if (result.x < -1. || result.y < -1. || result.z < -1. || result.x > 1 || \
		result.y > 1 || result.z > 1)
		puterr_and_exit("Normal orient vector must be in range [-1.0, 1.0] : "\
			, token);
	free_tokens(temp);
	return (vec_normalize(result));
}

int	parse_camera_fov(char *token, double aspect_ratio)
{
	int		i;
	double	fov;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || ft_cinstr(token[i], ",.-")))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	fov = ft_atoi(token);
	if (fov <= 0. || fov >= 180.)
		puterr_and_exit("Camera FOV must be in range (0, 180) : ", token);
	fov = fov * PI / 180;
	fov = 2 * atan(aspect_ratio * tan(fov / 2));
	fov = fov * 180 / PI;
	return (fov);
}
