/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 17:41:15 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 16:19:46 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	exit_hook(void *arg)
{
	(void) arg;
	exit(0);
}

int	esc_key_hook(int key)
{
	if (key == KEY_ESC)
		exit_hook(NULL);
	return (0);
}
