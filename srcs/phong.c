/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phong.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:10:53 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/20 11:27:44 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	phong_lighting(t_info *info, t_hit_record *rec)
{
	t_vec	light;

	light = new_vector(0, 0, 0);
	light = vec_sum(light, info->light.ambient);
	return (vec_to_color(light));
}
