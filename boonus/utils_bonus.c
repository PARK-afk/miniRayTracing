/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 17:01:11 by suhyun            #+#    #+#             */
/*   Updated: 2024/01/04 23:07:36 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	error_msg(char *msg)
{
	printf("Error: %s", msg);
	exit(1);
}

void	free_split(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	solve_quadratic(t_quad *q)
{
	q->discriminant = q->b * q->b - 4 * q->a * q->c;
	if (q->discriminant < 0)
	{
		q->tmp = -1;
		return ;
	}
	q->t1 = ((-1) * q->b - sqrt(q->discriminant)) / (2.0 * q->a);
	q->t2 = ((-1) * q->b + sqrt(q->discriminant)) / (2.0 * q->a);
	if (q->t1 > 0.0 && q->t2 > 0.0)
		q->tmp = q->t1;
	else if (q->t1 < 0.0 && q->t2 > 0.0)
		q->tmp = q->t2;
	if (q->t1 < 0.0 && q->t2 < 0.0)
		q->tmp = -1;
}

void	list_free(t_ob *element)
{
	t_ob	*temp;

	while (element != NULL)
	{
		temp = element->next;
		free(element);
		element = temp;
	}
}

void	all_list_free(t_scene *scene)
{
	list_free(scene->sphere);
	scene->sphere = NULL;
	list_free(scene->plane);
	scene->plane = NULL;
	list_free(scene->cylinder);
	scene->cylinder = NULL;
}
