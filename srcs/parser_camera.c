/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:49 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/04 20:26:27 by hocsong          ###   ########seoul.kr  */
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
	info->camera.fov = parse_camera_fov(tokens[2]);
	info->camera.is_camera_set = 1;
	info->camera.camera_to_world = get_camera_matrix(info->camera);
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
	if (vec_size(result) - 1 > 0.000000001)
		puterr_and_exit("Orient vector must have a size of 1 : ", token);
	free_tokens(temp);
	return (result);
}

int	parse_camera_fov(char *token)
{
	int	i;
	int	fov;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || ft_cinstr(token[i], ",.-")))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	fov = ft_atoi(token);
	if (fov < 0 || fov > 180)
		puterr_and_exit("Camera Field of View must be in range [0, 180] : ", \
			token);
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
