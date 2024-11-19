/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow_ob.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 22:55:44 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/05 20:30:13 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	shadow_cap(t_ray *ray, t_cap *cap)
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
		ray->t = t;
}

void	shadow_cylinder(t_ray *ray, t_ob *cy)
{
	t_quad	q;

	shadow_cap(ray, &cy->cap[0]);
	shadow_cap(ray, &cy->cap[1]);
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
		ray->t = q.tmp;
}

void	shadow_sphere(t_ray *ray, t_ob *sp)
{
	t_vec	l;
	double	tca;
	double	tnc;
	double	d2;
	double	tmp;

	l = vec_sub(sp->coordi, ray->coordi);
	tca = dot_prod(l, ray->dir);
	if (tca < 0)
		return ;
	d2 = dot_prod(l, l) - (tca * tca);
	if (d2 > sp->radius * sp->radius)
		return ;
	tnc = sqrt(sp->radius * sp->radius - d2);
	if (tca - tnc < EPSILON)
		tmp = tca + tnc;
	else
		tmp = tca - tnc;
	if ((ray->t < EPSILON && tmp > EPSILON) || (tmp > EPSILON && ray->t > tmp))
		ray->t = tmp;
}

void	shadow_plane(t_ray *ray, t_ob *plane)
{
	double	t;
	double	denom;

	denom = dot_prod(ray->dir, plane->normal);
	if (fabs(denom) < 1e-6)
		return ;
	t = dot_prod(vec_sub(plane->coordi, ray->coordi), plane->normal) / denom;
	if ((ray->t < EPSILON && t > EPSILON) || (t > EPSILON && ray->t > t))
		ray->t = t;
}
