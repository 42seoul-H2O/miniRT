/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:06 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 18:41:51 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_light_info(t_info *info, char **tokens)
{
	if (info->light.is_light_set)
		puterr_and_exit("Cannot be set light twice.", "");
	if (token_len(tokens) != 2)
		puterr_and_exit("Invalid tokens for setting light.", "");
	printf("Recognized Light_token : %s | %s\n", tokens[0], tokens[1]);
	info->light.is_light_set = 1;
	free(tokens[0]);
	free(tokens[1]);
}
