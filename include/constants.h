/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:33:19 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/14 16:28:13 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WHITESPACE (" \t\n\r\v\f")
# define PI 3.14159265358979323846264338327950288419716939937510582097494459230
# define DOUBLE_MAX 1.7976931348623157e+308

enum e_key {
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17,
	KEY_ESC = 53,
};

enum e_token {
	ERROR,
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
};

enum e_point {
	LATERAL,
	BOTTOM_BASE,
	TOP_BASE,
};

#endif