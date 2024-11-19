/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:12:03 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 23:03:40 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_ambient(char **split, t_scene *scene)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_msg("ambient input data\n");
	scene->ambient.ratio = get_ratio(split[1]);
	scene->ambient.color = get_color(split[2]);
	scene->ob_cnt[AMBIENT]++;
}

void	parse_camera(char **split, t_scene *scene)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 4)
		error_msg("camera input data\n");
	scene->camera.coordi = get_vector(split[1]);
	scene->camera.normal = get_nomalized_vec(split[2]);
	scene->camera.fov = ft_stod(split[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		error_msg("Fov range is 0 ~ 180\n");
	scene->ob_cnt[CAMERA]++;
}

void	parse_light(char **split, t_scene *scene)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	if (i != 4)
		error_msg("light input data\n");
	scene->light.coordi = get_vector(split[1]);
	scene->light.ratio = get_ratio(split[2]);
	scene->light.color = get_color(split[3]);
	scene->ob_cnt[LIGHT]++;
}
