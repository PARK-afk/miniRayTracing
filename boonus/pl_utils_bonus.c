/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:21:46 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 20:46:04 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	cos_pl(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	hit;
	double	cosine;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	cosine = dot_prod(obj->normal, light_dir);
	if (cosine < EPSILON)
		cosine = 0;
	return (cosine);
}

double	ref_pl(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	hit;
	t_vec	reflection;
	double	ret;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	reflection = vec_norm(reflective(obj->normal, light_dir));
	ret = dot_prod(vec_norm(vec_sub(ray->coordi, hit)), reflection);
	if (ret < EPSILON)
		ret = 0;
	return (ret);
}
