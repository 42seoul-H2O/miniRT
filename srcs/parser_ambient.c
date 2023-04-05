/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_ambient.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:18:38 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 18:41:01 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(t_info *info, char **tokens)
{
	if (info->light.is_ambient_set)
		puterr_and_exit("Cannot be set ambient light twice.", "");
	if (token_len(tokens) != 2)
		puterr_and_exit("Invalid tokens for setting ambient light.", "");
	printf("Recognized Ambient_light_token : %s | %s\n", tokens[0], tokens[1]);
	info->light.is_ambient_set = 1;
	free(tokens[0]);
	free(tokens[1]);
}
