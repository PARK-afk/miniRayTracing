/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 06:22:12 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 23:21:02 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	exit_hook(t_mlx	*data)
{
	(void)data;
	exit(0);
}

int	press_key(int key_val, t_mlx *data)
{
	if (key_val == KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->window);
		exit(0);
	}
	return (0);
}
