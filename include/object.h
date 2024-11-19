/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:01:48 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 23:25:55 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vector.h"
# define SHADOW 100

enum e_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	AMBIENT,
	CAMERA,
	LIGHT,
};

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}t_color;

typedef struct s_ambient
{
	double	ratio;
	t_color	color;
}t_ambient;

typedef struct s_camera
{
	t_vec	coordi;
	t_vec	normal;
	double	fov;
}t_camera;

typedef struct s_light
{
	t_vec	coordi;
	double	ratio;
	t_color	color;
}t_light;

typedef struct s_cap
{
	t_vec	coordi;
	t_vec	normal;
	double	diameter;
	double	radius;
	double	r2;
	t_color	color;
}t_cap;

typedef struct s_ob
{
	t_vec		coordi;
	t_vec		normal;
	double		diameter;
	double		height;
	t_color		color;
	double		radius;
	double		r2;
	t_cap		cap[2];
	struct s_ob	*next;
}t_ob;

// typedef struct s_sphere
// {
// 	t_vec			center;
// 	double			diameter;
// 	int				color[3];
// 	struct s_sphere	*next;
// }t_sphere;

// typedef struct s_plane
// {
// 	t_vec			origin;
// 	t_vec			normal;
// 	struct s_plane	*next;
// }t_plane;

// typedef struct s_cylinder
// {
// 	t_vec			origin;
// 	t_vec			normal;
// 	double			diameter;
// 	double			height;
// 	struct s_cylinder	*next;
// }t_cylinder;

#endif