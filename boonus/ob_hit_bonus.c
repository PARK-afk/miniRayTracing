/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ob_hit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:21:22 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 20:29:14 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	sp_ray_set(t_ray *ray, t_quad q, t_ob *sp, t_scene *scene)
{
	ray->t = q.tmp;
	ray->type = SPHERE;
	ray->obj = sp;
	ray_color_set(ray, sp->color);
	if (hit_shadow(ray, *scene))
		ray->type = SHADOW;
}

void	hit_sphere(t_ray *ray, t_ob *sp, t_scene *scene)
{
	t_quad	q;
	double	d2;

	q.oc = vec_sub(sp->coordi, ray->coordi);
	q.a = dot_prod(q.oc, ray->dir);
	if (q.a < 0)
		return ;
	d2 = dot_prod(q.oc, q.oc) - (q.a * q.a);
	if (d2 > sp->r2)
		return ;
	q.b = sqrt(sp->r2 - d2);
	if (q.a - q.b < EPSILON)
		q.tmp = q.a + q.b;
	else
		q.tmp = q.a - q.b;
	if ((ray->t < EPSILON && q.tmp > EPSILON) || \
			(q.tmp > EPSILON && ray->t > q.tmp))
		sp_ray_set(ray, q, sp, scene);
}

void	hit_plane(t_ray *ray, t_ob *plane, t_scene *scene)
{
	double	t;
	double	denom;

	denom = dot_prod(ray->dir, plane->normal);
	if (fabs(denom) < 1e-6)
		return ;
	t = dot_prod(vec_sub(plane->coordi, ray->coordi), plane->normal) / denom;
	if ((ray->t < EPSILON && t > EPSILON) || (t > EPSILON && ray->t > t))
	{
		ray->type = PLANE;
		ray->t = t;
		ray->obj = (void *)plane;
		ray_color_set(ray, plane->color);
		if (hit_shadow(ray, *scene))
			ray->type = SHADOW;
	}
}
