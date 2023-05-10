/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:59 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/10 21:23:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(t_info *info, char **tokens)
{
	t_cylinder	*shape;

	if (token_len(tokens) != 5)
		puterr_and_exit("Invalid tokens for making cylinder.", "");
	shape = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!shape)
		puterr_and_exit("Failed to allocate memory : ", "t_cylinder");
	shape->center = parse_coordinates(tokens[0]);
	shape->axis = parse_normal_orient_vec(tokens[1]);
	shape->diameter = parse_diameter_or_height(tokens[2]);
	shape->radius = shape->diameter / 2;
	shape->rsquare = shape->radius * shape->radius;
	shape->height = parse_diameter_or_height(tokens[3]);
	shape->cap_point = vec_sum(shape->center, \
			vec_mul(shape->axis, -(shape->height / 2)));
	shape->color = parse_shape_color(tokens[4]);
	node_append(info, new_node(CYLINDER, shape));
}
