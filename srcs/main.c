/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 09:00:35 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/06 20:12:50 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	intersection(t_ray *ray, t_scene *scene)
{
	int		i;
	int		type;
	t_ob	*ob[3];
	void	(*hit_func[3])(t_ray *, t_ob *, t_scene *);

	hit_func[SPHERE] = hit_sphere;
	hit_func[PLANE] = hit_plane;
	hit_func[CYLINDER] = hit_cylinder;
	ob[SPHERE] = scene->sphere;
	ob[PLANE] = scene->plane;
	ob[CYLINDER] = scene->cylinder;
	type = 0;
	while (type < 3)
	{
		i = 0;
		while (i < scene->ob_cnt[type])
		{
			hit_func[type](ray, ob[type], scene);
			if (ob[type]->next != NULL)
				ob[type] = ob[type]->next;
			i++;
		}
		type++;
	}
}

void	ray_set(t_ray *ray, t_mlx *mlx, t_scene *scene, int *xy)
{
	if (ray->t > 0)
	{
		if (ray->type == SHADOW)
			ray->color = color_scalar(ray->color, 0.85);
		ray_color(scene, ray);
		my_mlx_pixel_put(mlx, xy[0], xy[1], rgb_to_int(ray->color));
	}
	else
		my_mlx_pixel_put(mlx, xy[0], xy[1], 0x00ffffff);
}

void	raycasting(t_scene *scene, t_mlx *mlx)
{
	int		xy[2];
	t_ray	ray;
	double	uv[2];

	xy[1] = 0;
	while (xy[1] < scene->height)
	{
		xy[0] = 0;
		uv[1] = 2.0 * (double)xy[1] / (double)scene->height;
		while (xy[0] < scene->width)
		{
			uv[0] = scene->vport.aspect_ratio * 2.0 \
			* (double)xy[0] / (double)scene->width;
			ray = create_ray(scene, uv[0], uv[1]);
			intersection(&ray, scene);
			ray_set(&ray, mlx, scene, xy);
			xy[0]++;
		}
		xy[1]++;
	}
}

int	main(int ac, char **av)
{
	t_scene	scene;
	t_mlx	mlx;
	int		w[2];

	if (ac != 4 || av[1] == NULL)
		error_msg("input argument\n");
	init_scene(&scene);
	parse_data(av[1], &scene);
	m_init(&mlx, av[2], av[3], w);
	scene.width = w[0];
	scene.height = w[1];
	scene.vport = cam2view(&scene.camera, w[0], w[1]);
	raycasting(&scene, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, mlx.img, 0, 0);
	mlx_hook(mlx.window, 2, 0, press_key, &mlx);
	mlx_hook(mlx.window, X_EVENT_KEY_EXIT, 0, exit_hook, 0);
	mlx_loop(mlx.mlx);
	all_list_free(&scene);
	return (0);
}
