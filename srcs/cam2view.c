/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam2view.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:44:01 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/06 20:17:29 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	get_vport_right(t_camera *cam, t_vport *vport)
{
	if (cam->normal.y == 1 && cam->normal.x == 0 && cam->normal.z == 0)
		vport->ri_dir = cross_prod(cam->normal, vec3(0, 0, 1));
	else if (cam->normal.y == -1 && cam->normal.x == 0 && cam->normal.z == 0)
		vport->ri_dir = cross_prod(cam->normal, vec3(0, 0, -1));
	else
		vport->ri_dir = cross_prod(cam->normal, vec3(0, 1, 0));
}

t_vport	cam2view(t_camera *camera, int width, int height)
{
	t_vport	vport;
	t_vec	tmp[2];
	double	fov_radian;

	vport.v_height = 2.0;
	vport.aspect_ratio = (double)width / (double)height;
	vport.v_width = vport.v_height * vport.aspect_ratio;
	fov_radian = (double)camera->fov * M_PI / 180;
	vport.forcal_len = 1.0 / tan(fov_radian * 0.5);
	vport.center = vec_scalar(camera->normal, vport.forcal_len);
	get_vport_right(camera, &vport);
	tmp[0] = vec_scalar(vport.ri_dir, vport.v_width * 0.5);
	vport.up_dir = cross_prod(vport.ri_dir, camera->normal);
	tmp[1] = vec_scalar(vport.up_dir, vport.v_height * 0.5);
	tmp[0] = vec_sub(vport.center, tmp[0]);
	vport.left_up = vec_add(tmp[0], tmp[1]);
	return (vport);
}

t_ray	create_ray(t_scene *scene, double u, double v)
{
	t_ray	ray;
	t_vec	tmp;

	ray.coordi = scene->camera.coordi;
	tmp = vec_add(scene->vport.left_up, vec_scalar(scene->vport.ri_dir, u));
	tmp = vec_add(tmp, vec_scalar(scene->vport.up_dir, -v));
	ray.dir = vec_norm(tmp);
	ray.t = -1;
	return (ray);
}
