/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxutils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 17:39:57 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/06 17:52:11 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	m_init(t_mlx *mlx, char *width, char *height, int *wh)
{
	wh[0] = ft_atoi(width);
	if (wh[0] > 1920 || wh[0] < 0)
		wh[0] = 1920;
	wh[1] = ft_atoi(height);
	if (wh[1] > 1080 || wh[1] < 0)
		wh[1] = 1080;
	mlx->mlx = mlx_init();
	mlx->window = mlx_new_window(mlx->mlx, wh[0], wh[1], "miniRT");
	mlx->img = mlx_new_image(mlx->mlx, wh[0], wh[1]);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, \
									&mlx->line_length, &mlx->endian);
}
