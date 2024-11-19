/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:38 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 23:21:01 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	set_vec(t_vec *vec, double x, double y, double z)
{
	vec->x = x;
	vec->y = y;
	vec->z = z;
}

void	set_color(t_color *color)
{
	color->r = -1;
	color->g = -1;
	color->b = -1;
}

void	init_cnt(int *cnt)
{
	cnt[AMBIENT] = 0;
	cnt[CAMERA] = 0;
	cnt[LIGHT] = 0;
	cnt[SPHERE] = 0;
	cnt[PLANE] = 0;
	cnt[CYLINDER] = 0;
}

void	init_scene(t_scene *scene)
{
	scene->ambient.ratio = -1;
	set_color(&scene->ambient.color);
	set_vec(&scene->camera.coordi, -1, -1, -1);
	set_vec(&scene->camera.normal, -1, -1, -1);
	scene->camera.fov = -1;
	set_vec(&scene->light.coordi, -1, -1, -1);
	set_color(&scene->light.color);
	scene->light.ratio = -1;
	scene->sphere = NULL;
	scene->plane = NULL;
	scene->cylinder = NULL;
	init_cnt(scene->ob_cnt);
}
