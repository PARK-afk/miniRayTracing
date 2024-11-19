/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suhyun <suhyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 07:43:19 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 21:01:14 by suhyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}t_vec;

typedef struct s_quad
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t1;
	double	t2;
	double	tmp;
}t_quad;

t_vec	vec_add(t_vec vec1, t_vec vec2);
t_vec	vec_sub(t_vec vec1, t_vec vec2);
t_vec	cross_prod(t_vec vec1, t_vec vec2);
double	dot_prod(t_vec vec1, t_vec vec2);
t_vec	vec_norm(t_vec vec);
t_vec	vec_scalar(t_vec vec, double t);
double	vec_length(t_vec vec);
t_vec	vec3(double x, double y, double z);
t_vec	vec_minus(t_vec vec);

#endif