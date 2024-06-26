/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hocsong <hocsong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:48:11 by hyunjuki          #+#    #+#             */
/*   Updated: 2023/05/25 17:02:50 by hocsong          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vector
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_vec;

typedef struct s_matrix
{
	int		row_dimension;
	int		column_dimension;
	double	*data;
}				t_matrix;

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
	double	diameter;
}				t_sphere;

typedef struct s_plane
{
	t_color	color;
	t_point	center;
	t_vec	normal;
}				t_plane;

typedef struct s_cylinder
{
	t_color		color;
	t_point		center;
	t_vec		axis;
	double		diameter;
	double		height;
	t_matrix	*cylinder_to_world;
	t_matrix	*world_to_cylinder;
}				t_cylinder;

typedef struct s_blackhole
{
	t_color	color;
}				t_blackhole;

typedef struct s_shapelist
{
	int					type;
	void				*shape;
	struct s_shapelist	*next;
}				t_shapelst;

typedef struct s_camera
{
	int				is_camera_set;
	t_point			viewpoint;
	t_vec			orient;
	unsigned char	fov;
	t_matrix		*camera_to_world;
}				t_camera;

typedef struct s_light
{
	int			is_ambient_set;
	int			is_light_set;
	float		ambient_normalized_radiance;
	t_color		ambient_color;
	t_point		light_coor;
	float		normalized_radiance;
	t_matrix	*light_to_world;
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
	t_imgdata	data;
	t_shapelst	*shapes;
	t_camera	camera;
	t_light		light;
}				t_info;

typedef struct s_spherical_coord
{
	double	phi;
	double	theta;
}				t_spherical_coord;

#endif