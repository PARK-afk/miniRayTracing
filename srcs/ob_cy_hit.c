/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ob_cy_hit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:21:14 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/06 20:48:57 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	hit_cap(t_ray *ray, t_ob *cy, t_cap *cap)
{
	double	t;
	double	denom;
	t_vec	hit;

	denom = dot_prod(ray->dir, cap->normal);
	if (fabs(denom) < EPSILON)
		return ;
	t = dot_prod(vec_sub(cap->coordi, ray->coordi), cap->normal) / denom;
	hit = vec_add(ray->coordi, vec_scalar(ray->dir, t));
	if (t < EPSILON || vec_length(vec_sub(hit, cap->coordi)) > cap->radius)
		return ;
	if ((ray->t < EPSILON && t > EPSILON) || (t > EPSILON && ray->t > t))
	{
		ray->type = PLANE;
		ray->t = t;
		ray->obj = (void *)cap;
		ray->color = cy->color;
	}
}

bool	finite_height(t_ray *ray, t_ob *cy, double t)
{
	t_vec	hit;
	double	height[2];

	hit = vec_add(ray->coordi, vec_scalar(ray->dir, t));
	height[0] = dot_prod(vec_sub(hit, cy->coordi), cy->normal);
	height[1] = dot_prod(vec_sub(hit, cy->coordi), vec_scalar(cy->normal, -1));
	if (height[0] > 0 && height[0] > cy->height * 0.5)
		return (false);
	if (height[1] > 0 && height[1] > cy->height * 0.5)
		return (false);
	return (true);
}

void	hit_cylinder(t_ray *ray, t_ob *cy, t_scene *scene)
{
	t_quad	q;

	hit_cap(ray, cy, &cy->cap[0]);
	hit_cap(ray, cy, &cy->cap[1]);
	q.oc = vec_sub(ray->coordi, cy->coordi);
	q.a = dot_prod(ray->dir, ray->dir) - pow(dot_prod(ray->dir, cy->normal), 2);
	q.b = 2 * (dot_prod(ray->dir, q.oc) - dot_prod(ray->dir, cy->normal) * \
		dot_prod(q.oc, cy->normal));
	q.c = dot_prod(q.oc, q.oc) - pow(dot_prod(q.oc, cy->normal), 2) - cy->r2;
	solve_quadratic(&q);
	if (finite_height(ray, cy, q.tmp) == false)
		return ;
	if ((ray->t < EPSILON && q.tmp > EPSILON) || \
			(q.tmp > EPSILON && ray->t > q.tmp))
	{
		ray->type = CYLINDER;
		ray->t = q.tmp;
		ray->obj = (void *)cy;
		ray_color_set(ray, cy->color);
		if (hit_shadow(ray, *scene))
			ray->type = SHADOW;
	}
}
