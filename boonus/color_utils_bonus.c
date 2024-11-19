/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:19:59 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 21:21:12 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	color2rgb(t_color c)
{
	int	color;

	color = (int)(c.r * 255) << 16;
	color += (int)(c.g * 255) << 8;
	color += (int)(c.b * 255);
	return (color);
}

int	rgb_to_int(t_color color)
{
	return ((color.r << 16) | (color.g << 8) | color.b);
}

t_color	color_scalar(t_color color, double scalar)
{
	t_color	ret;

	ret.r = color.r * scalar;
	ret.g = color.g * scalar;
	ret.b = color.b * scalar;
	return (ret);
}

void	ray_color_set(t_ray *ray, t_color color)
{
	ray->color.r = color.r;
	ray->color.g = color.g;
	ray->color.b = color.b;
}
