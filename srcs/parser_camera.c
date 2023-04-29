/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:49 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/29 17:14:43 by hyunjuki         ###   ########.fr       */
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
	info->camera.vp.height = 2.0 * tan(info->camera.vfov / 2.0);
	info->camera.vp.width = info->camera.vp.height * info->aspect_ratio;
	info->camera.vp.focal_len = 1.0;
	info->camera.vp.horizontal = new_vector(info->camera.vp.width, 0, 0);
	info->camera.vp.vertical = new_vector(0, info->camera.vp.height, 0);
	info->camera.vp.left_bot = vec_sub(info->camera.viewpoint, new_vector(\
			info->camera.vp.width / (2), info->camera.vp.height / (2), \
			info->camera.vp.focal_len * (1)));
	info->camera.is_camera_set = 1;
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
	return (result);
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
	if (fov < 0. || fov > 180.)
		puterr_and_exit("Camera FOV must be in range [0, 180] : ", token);
	fov = 2 * atan(aspect_ratio * tan(fov / 2));
	return (fov);
}

int	ft_cinstr(int c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}
