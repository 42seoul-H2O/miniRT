/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:59 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 18:41:40 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_cylinder(t_info *info, char **tokens)
{
	(void) info;
	if (token_len(tokens) != 5)
		puterr_and_exit("Invalid tokens for making cylinder.", "");
	printf("Recognized Cylinder_token : %s | %s | %s | %s | %s\n", \
		tokens[0], tokens[1], tokens[2], tokens[3], tokens[4]);
	free(tokens[0]);
	free(tokens[1]);
	free(tokens[2]);
	free(tokens[3]);
	free(tokens[4]);
}
