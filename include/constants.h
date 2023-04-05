/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constants.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 21:33:19 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/05 16:48:12 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONSTANTS_H
# define CONSTANTS_H

# define WHITESPACE (" \t\n\r\v\f")

enum e_key {
	X_EVENT_KEY_PRESS = 2,
	X_EVENT_KEY_EXIT = 17,
	KEY_ESC = 53,
};

enum e_window{
	WINDOW_WIDTH = 1920,
	WINDOW_HEIGHT = 1080,
};

#endif