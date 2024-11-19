/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:20:45 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/04 23:20:49 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

double	get_ratio(char *str)
{
	double	ratio;

	if (str == NULL)
		error_msg("ratio empty format\n");
	ratio = ft_stod(str);
	if (ratio < 0 || ratio > 1)
		error_msg("ratio range\n");
	return (ratio);
}

double	get_diameter(char *str)
{
	double	diameter;

	if (str == NULL)
		error_msg("diameter empty format\n");
	diameter = ft_stod(str);
	if (diameter < 0)
		error_msg("diameter range\n");
	return (diameter);
}

double	get_height(char *str)
{
	double	height;

	if (str == NULL)
		error_msg("height empty format\n");
	height = ft_stod(str);
	if (height < 0)
		error_msg("height range\n");
	return (height);
}
