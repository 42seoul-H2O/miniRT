/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:06 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 13:56:23 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light_info(t_info *info, char **tokens)
{
	if (info->light.is_light_set)
		puterr_and_exit("Cannot be set light twice.", "");
	if (token_len(tokens) != 2)
		puterr_and_exit("Invalid tokens for setting light.", "");
	info->light.light_coor = parse_coordinates(tokens[0]);
	parse_brightness(info, tokens[1]);
	printf("Light_token parsed : %lf,%lf,%lf | %f\n", \
		info->light.light_coor.x, info->light.light_coor.y, \
		info->light.light_coor.z, info->light.brightness);
	info->light.is_light_set = 1;
}

void	parse_brightness(t_info *info, char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == '.'))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	info->light.brightness = ft_atof(token);
	if (info->light.brightness < 0. || info->light.brightness > 1.)
		puterr_and_exit("light brightness must be in range [0.0, 1.0] : ", \
			token);
}
