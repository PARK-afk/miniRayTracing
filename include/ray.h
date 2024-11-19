/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 08:07:03 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/06 20:48:24 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vector.h"

typedef struct s_ray
{
	t_vec	coordi;
	t_vec	dir;
	t_color	color;
	double	t;
	int		type;
	void	*obj;
}t_ray;

#endif