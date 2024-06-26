/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 14:47:42 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_info *info, char **tokens)
{
	t_plane	*shape;

	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for making plane.", "");
	shape = (t_plane *)malloc(sizeof(t_plane));
	if (!shape)
		puterr_and_exit("Failed to allocate memory : ", "t_plane");
	shape->center = parse_coordinates(tokens[0]);
	shape->normal = parse_normal_orient_vec(tokens[1]);
	shape->color = parse_shape_color(tokens[2]);
	node_append(info, new_node(PLANE, shape));
}
