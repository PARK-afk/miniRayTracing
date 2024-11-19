/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sp_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:23:35 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 21:29:39 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	cos_sp(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	normal;
	t_vec	hit;
	double	cosine;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	normal = vec_norm(vec_sub(hit, obj->coordi));
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	cosine = dot_prod(normal, light_dir);
	if (cosine < EPSILON)
		cosine = EPSILON;
	return (cosine);
}

double	ref_sp(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	normal;
	t_vec	hit;
	t_vec	reflection;
	double	ret;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	normal = vec_norm(vec_sub(hit, obj->coordi));
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	reflection = vec_norm(reflective(normal, light_dir));
	ret = dot_prod(vec_norm(vec_sub(ray->coordi, hit)), vec_norm(reflection));
	if (ret < EPSILON)
		ret = EPSILON;
	return (ret);
}

t_vec	reflective(t_vec normal, t_vec light_dir)
{
	t_vec	reflection;

	reflection = vec_sub(vec_scalar(normal, 2 * \
					dot_prod(normal, light_dir)), light_dir);
	return (reflection);
}
