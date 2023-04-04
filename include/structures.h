/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:48:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/04 18:26:06 by hyunjuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
}				t_vec;

typedef struct s_vector	t_point;
typedef double			t_scalar;

typedef struct s_color
{
	unsigned char	red;
	unsigned char	blue;
	unsigned char	green;
}				t_color;

typedef struct s_sphere
{
	t_color	color;
	t_point	center;
	float	diameter;
}				t_sphere;

typedef struct s_plane
{
	t_color	color;
	t_point	center;
	t_vec	normal;
}				t_plane;

typedef struct s_cylinder
{
	t_color	color;
	t_point	center;
	t_vec	axis;
	float	diameter;
	float	height;
}				t_cylinder;

typedef struct s_shapelist
{
	int					type;
	void				*shape;
	struct s_shapelist	*next;
}				t_shapelst;

typedef struct s_camera
{
	t_point			viewpoint;
	t_vec			orient;
	unsigned char	fov;
}t_camera;

typedef struct s_light
{
	float	al_ratio;
	t_color	al_color;
	t_point	light_coor;
	float	brightness;
}t_light;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	int			width;
	int			height;
	t_shapelst	*shapes;
	t_camera	camera;
	t_light		light;
}t_info;

#endif