/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:20:56 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/05 21:55:56 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	check_noraml(t_vec v)
{
	if (v.x == 0 && v.y == 0 && v.z == 0)
		error_msg("Please enter at least one direction vector\n");
}

t_vec	get_nomalized_vec(char *str)
{
	int		i;
	char	**split;
	t_vec	tmp;
	t_vec	vec;

	i = 0;
	split = ft_split(str, ",");
	if (split[0] == NULL || split[1] == NULL || split[2] == NULL)
		error_msg("vector empty format\n");
	while (split[i])
		i++;
	if (i != 3)
		error_msg("vector format\n");
	tmp.x = ft_stod(split[0]);
	tmp.y = ft_stod(split[1]);
	tmp.z = ft_stod(split[2]);
	if ((tmp.x < -1 || tmp.x > 1) || (tmp.y < -1 || tmp.y > 1) \
		|| (tmp.z < -1 || tmp.z > 1))
		error_msg("vector range\n");
	free_split(split);
	check_noraml(tmp);
	vec = vec_norm(tmp);
	return (vec);
}

t_vec	get_vector(char *str)
{
	int		i;
	t_vec	vec;
	char	**split;

	i = 0;
	split = ft_split(str, ",");
	if (split[0] == NULL || split[1] == NULL || split[2] == NULL)
		error_msg("vector empty format\n");
	while (split[i])
		i++;
	if (i != 3)
		error_msg("vector format\n");
	vec.x = ft_stod(split[0]);
	vec.y = ft_stod(split[1]);
	vec.z = ft_stod(split[2]);
	free_split(split);
	return (vec);
}
