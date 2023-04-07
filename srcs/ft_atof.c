/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:35:33 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/07 15:20:41 by hyunjuki         ###   ########.fr       */
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
	if (*str != '\0')
		return (10);
	if (minus < 0)
		result *= -1;
	return (result);
}

double	ft_atof(const char *str)
{
	char	*temp;
	double	result;
	double	frac;
	int		minus;

	if (!str)
		return (0);
	temp = (char *)str;
	result = (double)ft_atoi(str);
	minus = 1;
	if (*str == '-')
		minus = -1;
	while (*str && *str != '.')
		str++;
	frac = parse_fractional(minus, ++str);
	if (frac >= 1)
		puterr_and_exit("Invalid frational token. : ", temp);
	result += frac;
	return (result);
}
