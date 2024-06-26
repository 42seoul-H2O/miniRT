/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapelst_oper1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:32:18 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 14:17:11 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_shapelst	*new_node(int shape_type, void *shape)
{
	t_shapelst	*result;

	result = (t_shapelst *)malloc(sizeof(t_shapelst));
	if (!result)
		return (NULL);
	result->type = shape_type;
	result->shape = shape;
	result->next = NULL;
	return (result);
}

void	free_node(t_shapelst *node)
{
	if (!node)
		return ;
	if (node->shape)
		free(node->shape);
	node->shape = NULL;
	node->next = NULL;
	free(node);
}

void	free_shapelst(t_shapelst *head)
{
	t_shapelst	*temp;
	t_shapelst	*curr;

	if (!head)
		return ;
	curr = head;
	while (curr)
	{
		temp = curr->next;
		free_node(curr);
		curr = temp;
	}
}

t_shapelst	*get_last(t_shapelst *node)
{
	t_shapelst	*temp;

	if (!node)
		return (NULL);
	temp = node;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

void	node_append(t_info *info, t_shapelst *node)
{
	if (!(info) || !node)
		return ;
	if (!(info->shapes))
		info->shapes = node;
	else
		get_last(info->shapes)->next = node;
}
