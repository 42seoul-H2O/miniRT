/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:38 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 13:43:50 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(t_info *info, char **tokens)
{
	if (info->light.is_ambient_set)
		puterr_and_exit("Cannot be set ambient light twice.", "");
	if (token_len(tokens) != 2)
		puterr_and_exit("Invalid tokens for setting ambient light.", "");
	parse_am_light_ratio(info, tokens[0]);
	parse_am_light_color(info, tokens[1]);
	printf("Ambient_light_token parsed : %f | %d\n", \
		info->light.al_ratio, color_to_int(info->light.al_color));
	info->light.is_ambient_set = 1;
}

void	parse_am_light_ratio(t_info *info, char *token)
{
	int	i;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == '.'))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	info->light.al_ratio = ft_atof(token);
	if (info->light.al_ratio < 0. || info->light.al_ratio > 1.)
		puterr_and_exit("Ambient light ratio must be in range [0.0, 1.0] : ", \
			token);
}

void	parse_am_light_color(t_info *info, char *token)
{
	int		i;
	char	**temp;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == ','))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	temp = ft_split(token, ',');
	check_rgb_token(token, temp);
	info->light.al_color = new_color((unsigned char)ft_atoi(temp[0]), \
		(unsigned char)ft_atoi(temp[1]), (unsigned char)ft_atoi(temp[2]));
	free_tokens(temp);
}

void	check_rgb_token(char *str, char **tokens)
{
	int	color_val;

	if (!tokens)
		puterr_and_exit("Cannot split RGB token. : ", str);
	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid RGB token. : ", str);
	color_val = ft_atoi(tokens[0]);
	if (color_val < 0 || color_val > 255)
		puterr_and_exit("RGB Color value must be in range [0, 255]. : ", str);
	color_val = ft_atoi(tokens[1]);
	if (color_val < 0 || color_val > 255)
		puterr_and_exit("RGB Color value must be in range [0, 255]. : ", str);
	color_val = ft_atoi(tokens[2]);
	if (color_val < 0 || color_val > 255)
		puterr_and_exit("RGB Color value must be in range [0, 255]. : ", str);
}
