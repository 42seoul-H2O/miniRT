/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 18:42:00 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_plane(t_info *info, char **tokens)
{
	(void) info;
	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for making plane.", "");
	printf("Recognized Plane_token : %s | %s | %s\n", \
		tokens[0], tokens[1], tokens[2]);
	free(tokens[0]);
	free(tokens[1]);
	free(tokens[2]);
}
