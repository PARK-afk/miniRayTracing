/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lightcalculate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 21:17:57 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/05 21:05:17 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	phong_light(t_ray *ray, t_scene *scene, double angle, int idx)
{
	int		clr;
	int		ret;

	(void)ray;
	clr = 0;
	if (idx == 0)
		clr = scene->light.color.r;
	else if (idx == 1)
		clr = scene->light.color.g;
	else if (idx == 2)
		clr = scene->light.color.b;
	ret = (double)clr * scene->light.ratio * pow(angle, 20);
	return (ret);
}

int	ambient_light(t_ray *ray, t_scene *scene, int idx)
{
	int	ret;
	int	clr;
	int	sab;

	clr = 0;
	sab = 0;
	if (idx == 0)
	{
		clr = ray->color.r;
		sab = scene->ambient.color.r;
	}
	else if (idx == 1)
	{	
		clr = ray->color.g;
		sab = scene->ambient.color.g;
	}
	else if (idx == 2)
	{
		clr = ray->color.b;
		sab = scene->ambient.color.b;
	}
	ret = (double)clr * scene->ambient.ratio * \
	((double)sab / 255.0);
	return (ret);
}

int	diffuse_light(t_ray *ray, t_scene *scene, double angle, int idx)
{
	int	ret;
	int	clr;
	int	sab;

	clr = 0;
	sab = 0;
	if (idx == 0)
	{
		clr = ray->color.r;
		sab = scene->light.color.r;
	}
	else if (idx == 1)
	{	
		clr = ray->color.g;
		sab = scene->light.color.g;
	}
	else if (idx == 2)
	{
		clr = ray->color.b;
		sab = scene->light.color.b;
	}
	ret = (double)clr * angle * scene->light.ratio * \
	((double)sab / 255.0);
	return (ret);
}

int	add_color(t_scene scene, t_ray *ray, double *angle, int idx)
{
	int	color;

	color = ambient_light(ray, &scene, idx);
	if (ray->type != SHADOW)
		color += diffuse_light(ray, &scene, angle[0], idx) \
		+ phong_light(ray, &scene, angle[1], idx);
	if (color > 255)
		color = 255;
	return (color);
}

void	ray_color(t_scene *scene, t_ray *ray)
{
	double	angle[2];

	if (ray->type == SPHERE)
	{
		angle[0] = cos_sp(ray->obj, ray, scene);
		angle[1] = ref_sp(ray->obj, ray, scene);
	}
	else if (ray->type == PLANE)
	{
		angle[0] = cos_pl(ray->obj, ray, scene);
		angle[1] = ref_pl(ray->obj, ray, scene);
	}
	else if (ray->type == CYLINDER)
	{
		angle[0] = cos_cy(ray->obj, ray, scene);
		angle[1] = ref_cy(ray->obj, ray, scene);
	}
	else
	{
		angle[0] = 0.0;
		angle[1] = 0.0;
	}
	ray->color.r = add_color(*scene, ray, angle, 0);
	ray->color.g = add_color(*scene, ray, angle, 1);
	ray->color.b = add_color(*scene, ray, angle, 2);
}
