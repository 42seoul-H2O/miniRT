/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:59:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 11:44:02 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
		free(temp);
		parse_tokens(info, tokens);
		line = get_next_line(scene_fd);
	}
	if (!(info->camera.is_camera_set && info->light.is_ambient_set \
		&& info->light.is_light_set))
		puterr_and_exit("Configuration is incomplete.", "");
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
	if (*tokens == NULL)
		return (free(tokens));
	if (ft_strncmp(*tokens, "A", 2) == 0)
		parse_ambient_light(info, tokens + 1);
	else if (ft_strncmp(*tokens, "C", 2) == 0)
		parse_camera_info(info, tokens + 1);
	else if (ft_strncmp(*tokens, "L", 2) == 0)
		parse_light_info(info, tokens + 1);
	else if (ft_strncmp(*tokens, "sp", 3) == 0)
		parse_sphere(info, tokens + 1);
	else if (ft_strncmp(*tokens, "pl", 3) == 0)
		parse_plane(info, tokens + 1);
	else if (ft_strncmp(*tokens, "cy", 3) == 0)
		parse_cylinder(info, tokens + 1);
	else
		puterr_and_exit("Invalid identifier : ", *tokens);
	free_tokens(tokens);
}

int	token_len(char **tokens)
{
	int	len;

	len = 0;
	while (*tokens != NULL)
	{
		len++;
		tokens++;
	}
	return (len);
}

void	free_tokens(char **tokens)
{
	int	i;

	if (!tokens)
		return ;
	i = 0;
	while (tokens[i] != NULL)
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}
