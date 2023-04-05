/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:59:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 17:11:04 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	parse_scene(t_info *info, int scene_fd)
{
	char	*line;
	char	*temp;

	line = get_next_line(scene_fd);
	while (line)
	{
		temp = ft_strtrim(line, WHITESPACE);
		free(line);
		if (!temp)
			puterr_and_exit("Failed to allocate memory while parsing.", "");
		if (!check_type(info, temp))
			puterr_and_exit("Invalid identifier : ", temp);
		free(temp);
		line = get_next_line(scene_fd);
	}
}

int	check_identifier(t_info *info, char *str)
{
	return (1);
}
