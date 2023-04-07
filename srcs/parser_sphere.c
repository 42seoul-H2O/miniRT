/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:15 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 11:21:52 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(t_info *info, char **tokens)
{
	(void) info;
	if (token_len(tokens) != 3)
		puterr_and_exit("Invalid tokens for making sphere.", "");
	printf("Recognized Sphere_token : %s | %s | %s\n", \
		tokens[0], tokens[1], tokens[2]);
}
