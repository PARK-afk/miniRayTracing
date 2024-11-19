/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cy_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:20:33 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 21:00:23 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	get_hit_height(t_ob *cy, t_vec hit)
{
	double	hit_height;
	double	dist;
	t_vec	center_to_hit;

	center_to_hit = vec_sub(hit, cy->coordi);
	dist = vec_length(center_to_hit);
	if (dist < cy->radius)
		dist = cy->radius;
	hit_height = sqrt(pow(dist, 2) - cy->r2);
	if (dot_prod(center_to_hit, cy->normal) < EPSILON)
		return (-1.0 * hit_height);
	else
		return (hit_height);
}

double	cos_cy(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	normal;
	t_vec	hit;
	double	cosine;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	normal = vec_sub(hit, vec_add(obj->coordi, \
				vec_scalar(obj->normal, get_hit_height(obj, hit))));
	normal = vec_norm(normal);
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	cosine = dot_prod(normal, light_dir);
	if (cosine < EPSILON)
		cosine = 0;
	return (cosine);
}

double	ref_cy(t_ob *obj, t_ray *ray, t_scene *scene)
{
	t_vec	light_dir;
	t_vec	normal;
	t_vec	hit;
	t_vec	reflection;
	double	ret;

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	light_dir = vec_norm(vec_sub(scene->light.coordi, hit));
	normal = vec_sub(hit, vec_add(obj->coordi, \
				vec_scalar(obj->normal, get_hit_height(obj, hit))));
	normal = vec_norm(normal);
	reflection = vec_norm(reflective(normal, light_dir));
	ret = dot_prod(vec_norm(vec_sub(ray->coordi, hit)), reflection);
	if (ret < EPSILON)
		ret = 0;
	return (ret);
}
