/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_camera.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:49 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 18:41:25 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_camera_info(t_info *info, char **tokens)
{
	if (info->camera.is_camera_set)
		puterr_and_exit("Cannot be set camera twice.", "");
	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for setting camera.", "");
	printf("Recognized Camera_token : %s | %s | %s\n", \
		tokens[0], tokens[1], tokens[2]);
	info->camera.is_camera_set = 1;
	free(tokens[0]);
	free(tokens[1]);
	free(tokens[2]);
}
