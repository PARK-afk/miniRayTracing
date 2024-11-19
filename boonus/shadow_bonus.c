/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:29:03 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/05 21:04:17 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	shadow_check(t_ray *ray, t_scene scene, int idx)
{
	while (idx < scene.ob_cnt[SPHERE])
	{
		shadow_sphere(ray, scene.sphere);
		if (scene.sphere->next)
			scene.sphere = scene.sphere->next;
		idx++;
	}
	idx = 0;
	while (idx < scene.ob_cnt[PLANE])
	{
		shadow_plane(ray, scene.plane);
		if (scene.plane->next)
			scene.plane = scene.plane->next;
		idx++;
	}
	idx = 0;
	while (idx < scene.ob_cnt[CYLINDER])
	{
		shadow_cylinder(ray, scene.cylinder);
		if (scene.cylinder->next)
			scene.cylinder = scene.cylinder->next;
		idx++;
	}
}

int	hit_shadow(t_ray *ray, t_scene scene)
{
	t_ray	hit;
	t_vec	to_light;
	double	range;
	int		idx;

	hit.coordi = vec_add(ray->coordi, vec_scalar(ray->dir, ray->t));
	to_light = vec_sub(scene.light.coordi, hit.coordi);
	hit.dir = vec_norm(to_light);
	hit.coordi = vec_add(hit.coordi, vec_scalar(hit.dir, 0.01));
	range = vec_length(to_light);
	hit.t = -1.0;
	hit.type = -1;
	hit.obj = NULL;
	hit.color.r = 0;
	hit.color.g = 0;
	hit.color.b = 0;
	idx = 0;
	shadow_check(&hit, scene, idx);
	if (hit.t > 0.0 && hit.t < range)
		return (1);
	else
		return (0);
}
