/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:06 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/25 21:27:29 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	*get_light_matrix(t_light light);

void	parse_light_info(t_info *info, char **tokens)
{
	if (info->light.is_light_set)
		puterr_and_exit("Cannot be set light twice.", "");
	if (token_len(tokens) != 2)
		puterr_and_exit("Invalid tokens for setting light.", "");
	info->light.light_coor = parse_coordinates(tokens[0]);
	parse_normalized_radiance(info, tokens[1]);
	info->light.light_to_world = get_light_matrix(info->light);
	info->light.is_light_set = 1;
}

void	parse_normalized_radiance(t_info *info, char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == '.'))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	info->light.normalized_radiance = ft_atof(token);
	if (info->light.normalized_radiance < 0. || \
		info->light.normalized_radiance > 1.)
		puterr_and_exit("light normalized_radiance must be \
						in range [0.0, 1.0] : ", token);
}

static t_matrix	*get_light_matrix(t_light light)
{
	t_point		translate;
	t_matrix	*matrix;

	translate = light.light_coor;
	matrix = init_matrix(4, 4);
	matrix->data[0] = 1;
	matrix->data[1] = 0;
	matrix->data[2] = 0;
	matrix->data[3] = translate.x;
	matrix->data[4] = 0;
	matrix->data[5] = 1;
	matrix->data[6] = 0;
	matrix->data[7] = translate.y;
	matrix->data[8] = 0;
	matrix->data[9] = 0;
	matrix->data[10] = 1;
	matrix->data[11] = translate.z;
	matrix->data[12] = 0;
	matrix->data[13] = 0;
	matrix->data[14] = 0;
	matrix->data[15] = 1;
	return (matrix);
}
