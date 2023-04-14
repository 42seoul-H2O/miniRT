/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:15 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/14 14:40:43 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_info *info, char **tokens)
{
	t_sphere	*shape;

	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for making sphere.", "");
	shape = (t_sphere *)malloc(sizeof(t_sphere));
	if (!shape)
		puterr_and_exit("Failed to allocate memory : ", "t_sphere");
	shape->center = parse_coordinates(tokens[0]);
	shape->radius = parse_diameter_or_height(tokens[1]) / 2;
	shape->rsquare = shape->radius * shape->radius;
	shape->color = parse_shape_color(tokens[2]);
	node_append(info, new_node(SPHERE, shape));
}

double	parse_diameter_or_height(char *token)
{
	int		i;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == '.'))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	return (ft_atof(token));
}

t_color	parse_shape_color(char *token)
{
	int		i;
	char	**temp;
	t_color	result;

	i = 0;
	while (token[i])
	{
		if (!(ft_isdigit(token[i]) || token[i] == ','))
			puterr_and_exit("Invalid token while parsing : ", token);
		i++;
	}
	temp = ft_split(token, ',');
	check_rgb_token(token, temp);
	result = new_color((unsigned char)ft_atoi(temp[0]), \
		(unsigned char)ft_atoi(temp[1]), (unsigned char)ft_atoi(temp[2]));
	free_tokens(temp);
	return (result);
}
