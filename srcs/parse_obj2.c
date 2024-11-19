/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_obj2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junsepar <junsepar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 23:21:36 by junsepar          #+#    #+#             */
/*   Updated: 2024/01/04 23:21:37 by junsepar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	add_node(t_ob **head, t_ob *new_node)
{
	t_ob	*temp;

	if (*head == NULL)
		*head = new_node;
	else
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	parse_sphere(char **split, t_scene *scene)
{
	int		i;
	t_ob	*new_node;

	i = 0;
	while (split[i])
		i++;
	if (i != 4)
		error_msg("sphere input data\n");
	new_node = (t_ob *)ft_calloc(1, sizeof(t_ob));
	if (new_node == NULL)
		error_msg("sphere malloc error\n");
	new_node->coordi = get_vector(split[1]);
	new_node->diameter = get_diameter(split[2]);
	new_node->color = get_color(split[3]);
	new_node->radius = new_node->diameter * 0.5;
	new_node->r2 = new_node->radius * new_node->radius;
	new_node->next = NULL;
	add_node(&(scene->sphere), new_node);
	scene->ob_cnt[SPHERE]++;
}

void	parse_plane(char **split, t_scene *scene)
{
	int		i;
	t_ob	*new_node;

	i = 0;
	while (split[i])
		i++;
	if (i != 4)
		error_msg("plane input data\n");
	new_node = (t_ob *)ft_calloc(1, sizeof(t_ob));
	if (new_node == NULL)
		error_msg("plane malloc error\n");
	new_node->coordi = get_vector(split[1]);
	new_node->normal = get_nomalized_vec(split[2]);
	new_node->color = get_color(split[3]);
	new_node->next = NULL;
	add_node(&(scene->plane), new_node);
	scene->ob_cnt[PLANE]++;
}

void	cap_set(t_ob *cy)
{
	cy->cap[0].coordi = vec_add(cy->coordi, \
					vec_scalar(cy->normal, cy->height * 0.5));
	cy->cap[0].normal = cy->normal;
	cy->cap[0].diameter = cy->diameter;
	cy->cap[0].radius = cy->diameter * 0.5;
	cy->cap[0].r2 = cy->cap[0].radius * cy->cap[0].radius;
	cy->cap[0].color = cy->color;
	cy->cap[1].coordi = vec_add(cy->coordi, \
					vec_scalar(cy->normal, -cy->height * 0.5));
	cy->cap[1].normal = vec_scalar(cy->normal, -1);
	cy->cap[1].diameter = cy->diameter;
	cy->cap[1].radius = cy->diameter * 0.5;
	cy->cap[1].r2 = cy->cap[1].radius * cy->cap[1].radius;
	cy->cap[1].color = cy->color;
}

void	parse_cylinder(char **split, t_scene *scene)
{
	int		i;
	t_ob	*new_node;

	i = 0;
	while (split[i])
		i++;
	if (i != 6)
		error_msg("cylinder input data\n");
	new_node = (t_ob *)ft_calloc(1, sizeof(t_ob));
	if (new_node == NULL)
		error_msg("sphere malloc error\n");
	new_node->coordi = get_vector(split[1]);
	new_node->normal = get_nomalized_vec(split[2]);
	new_node->diameter = get_diameter(split[3]);
	new_node->height = get_height(split[4]);
	new_node->color = get_color(split[5]);
	new_node->radius = new_node->diameter * 0.5;
	new_node->r2 = new_node->radius * new_node->radius;
	cap_set(new_node);
	new_node->next = NULL;
	add_node(&(scene->cylinder), new_node);
	scene->ob_cnt[CYLINDER]++;
}
