/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:57:30 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/05 21:22:28 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_range_color(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		check_result(split[i]);
		if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
			error_msg("color range\n");
		i++;
	}
}

t_color	get_color(char *str)
{
	int		i;
	t_color	color;
	char	**split;

	i = 0;
	split = ft_split(str, ",");
	if (split[0] == NULL || split[1] == NULL || split[2] == NULL)
		error_msg("color empty format\n");
	while (split[i])
		i++;
	if (i != 3)
		error_msg("color format\n");
	check_range_color(split);
	color.r = ft_stod(split[0]);
	color.g = ft_atoi(split[1]);
	color.b = ft_stod(split[2]);
	free_split(split);
	return (color);
}
