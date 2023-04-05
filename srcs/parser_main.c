/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:59:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 17:40:33 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	parse_scene(t_info *info, int scene_fd)
{
	char	*line;
	char	*temp;
	char	**tokens;

	line = get_next_line(scene_fd);
	while (line)
	{
		temp = ft_strtrim(line, WHITESPACE);
		free(line);
		if (!temp)
			puterr_and_exit("Failed to allocate memory while parsing.", "");
		change_white_spaces(temp);
		tokens = ft_split(temp, ' ');
		if (!tokens)
			puterr_and_exit("Failed to split scene string : ", temp);
		parse_tokens(info, tokens);
		free(tokens);
		free(temp);
		line = get_next_line(scene_fd);
	}
}

void	change_white_spaces(char *str)
{
	int	i;
	int	j;

	if (!str)
		return ;
	if (!ft_strlen(str))
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		j = 1;
		while (j < 6)
		{
			if (str[i] == WHITESPACE[j])
				str[i] = ' ';
			j++;
		}
		i++;
	}
}

void	parse_tokens(t_info *info, char **tokens)
{
	(void) info;
	if (*tokens == NULL)
		return ;
	while (*tokens != NULL)
	{
		printf("%s", *tokens);
		free(*tokens);
		tokens++;
		if (*tokens)
			printf("|");
	}
	printf("\n");
}
