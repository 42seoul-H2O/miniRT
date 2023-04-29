/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:33:19 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/29 17:12:04 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WHITESPACE (" \t\n\r\v\f")
# define PI 3.14159265358979323846264338327950288419716939937510582097494459230
# define SPECULAR_BRIGHTNESS 64
# define SPECULAR_STRENGTH 0.5
# define LUMEN 3

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

#endif