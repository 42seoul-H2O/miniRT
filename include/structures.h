/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjuki <hyunjuki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:48:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/04/18 15:24:32 by hyunjuki         ###   ########.fr       */
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
	double	radius;
	double	rsquare;
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
	double	diameter;
	double	height;
}				t_cylinder;

typedef struct s_shapelist
{
	int					type;
	void				*shape;
	struct s_shapelist	*next;
}				t_shapelst;

typedef struct s_viewport
{
	double		width;
	double		height;
	t_vec		horizontal;
	t_vec		vertical;
	double		focal_len;
	t_point		left_bot;
}				t_viewport;

typedef struct s_camera
{
	int				is_camera_set;
	t_point			viewpoint;
	t_vec			orient;
	unsigned char	fov;
	t_viewport		vp;
}				t_camera;

typedef struct s_light
{
	int		is_ambient_set;
	int		is_light_set;
	float	al_ratio;
	t_color	al_color;
	t_point	light_coor;
	float	brightness;
}				t_light;

typedef struct s_ray
{
	t_point	orig;
	t_vec	dir;
}				t_ray;

typedef struct s_imgdata
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_imgdata;

typedef struct s_info
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			scr_width;
	int			scr_height;
	double		aspect_ratio;
	t_imgdata	data;
	t_shapelst	*shapes;
	t_camera	camera;
	t_light		light;
}				t_info;

typedef struct s_hit_record
{
	t_point	p;
	t_vec	normal;
	double	dist;
	double	tmax;
	double	tmin;
	int		front_face;
}				t_hit_record;

#endif