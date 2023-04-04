/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:35:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/04 17:34:48 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	parse_fractional(int minus, const char *str)
{
	double		result;
	double		scale;

	result = 0;
	scale = 0.1;
	while (*str && ft_isdigit(*str))
	{
		result += scale * (*str - '0');
		scale /= 10;
		str++;
	}
	if (minus < 0)
		result *= -1;
	return (result);
}

double	ft_atof(const char *str)
{
	double	result;
	int		minus;

	if (!str)
		return (0);
	result = (double)ft_atoi(str);
	minus = 1;
	if (*str == '-')
		minus = -1;
	while (*str && *str != '.')
		str++;
	result += parse_fractional(minus, ++str);
	return (result);
}
